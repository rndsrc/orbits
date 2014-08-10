#include "orbits.h"
#include <unistd.h>
#include <cstdlib>
#include <cmath>

static int usage(const char *cmd)
{
	printf("usage: %s [[output_file] input_file]\n", cmd);
	return 0;
}

static FILE *out(const char *fmt, size_t i)
{
	char name[256];
	if(!fmt)
		return stdout;
	snprintf(name, sizeof(name), fmt, i);
	return fopen(name, "a");
}

int main(int argc, char **argv)
{
	const bool tty = isatty(fileno(stdin));
	if(tty && argc <= 1)
		printf("Please input initial conditions [Ctrl+D to exit]:\n");

	scheme *scm = get_scheme(argv[0]);
	FILE   *ini = (tty && argc > 1) ? fopen(argv[(argc--)-1], "r") : stdin;
	char   *fmt = argc > 1 ? argv[argc-1] : NULL;
	data   *d   = input(ini);
	if(d == NULL)
		return usage(argv[0]);

	real   dt_dump = 2.0 * M_PI / 32;
	size_t n_dump  = 3200;
	size_t n_inner = get_factor(argv[0]) * 10;

	fprintf(stderr, "%.16g\n", energy(d->p, d->n));
	for(size_t i = 0; i < n_dump; ++i) {
		real dt = dt_dump / n_inner;
		for(size_t h = 0; h < n_inner; ++h)
			scm(d, dt);

		fprintf(stderr, "%.16g\n", energy(d->p, d->n));
		output(out(fmt, i+1), d, argv[0], fmt);
	}
	return 0;
}
