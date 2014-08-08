#include "orbits.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

int main(int argc, char **argv)
{
	if(argc > 1 && !strcmp(argv[1], "--help")) {
		printf("usage: %s [step_size] < input_file\n", argv[0]);
		return 0;
	}

	real dt = argc > 1 ? atof(argv[1]) : 1e-3;
	printf("dt = %g\n", dt);

	return 0;
}
