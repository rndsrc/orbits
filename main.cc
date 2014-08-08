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

	data *d = input(stdin);

	return 0;
}
