#include "orbits.h"
#include <cstdlib>

static int usage(const char *cmd)
{
	printf("usage: %s [[output_file] input_file]\n", cmd);
	return 0;
}

int main(int argc, char **argv)
{
	scheme *scm = get_scheme(argv[0]);
	FILE   *ini = argc > 1 ? fopen(argv[argc-1], "r") : NULL;
	char   *fmt = argc > 2 ?       argv[argc-2]       : NULL;

	data *d = input(ini ? ini : stdin);
	if(d == NULL)
		return usage(argv[0]);

	for(size_t i = 0; i < 100; ++i) {
		char name[256];
		if(fmt)
			snprintf(name, sizeof(name), fmt, i+1);

		for(size_t h = 0; h < 6283; ++h)
			scm(d, 1e-3);

		FILE *out = fmt ? fopen(name, "a") : stdout;
		output(out, d, argv[0], fmt);
	}
	return 0;
}
