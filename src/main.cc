#include "orbits.h"
#include <cstdlib>

static int usage(const char *cmd)
{
	printf("usage: %s [step_size] < input_file\n", cmd);
	return 0;
}

int main(int argc, char **argv)
{
	scheme *scm = get_scheme(argv[0]);
	real    dt  = argc > 1 ? atof(argv[1]) : 1e-3;
	if(dt == 0.0)
		return usage(argv[0]);

	FILE *f = argc > 2 ? fopen(argv[argc-1], "r") : NULL;
	data *d = input(f ? f : stdin);
	if(d == NULL)
		return usage(argv[0]);

	for(size_t h = 0; h < 6283; ++h) {
		scm(d, dt);
		output(stdout, d, argv[0], dt);
	}
	return 0;
}
