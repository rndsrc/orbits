#include "orbits.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	real dt = argc > 1 ? atof(argv[1]) : 0.0;

	if(dt <= 0.0) {
		printf("usage: %s [step_size] < input_file\n", argv[0]);
		return 0;
	}
	printf("dt = %g\n", dt);

	FILE *f = argc > 2 ? fopen(argv[argc-1], "r") : NULL;
	data *d = input(f ? f : stdin);

	output(d, stdout);

	return 0;
}
