#include "orbits.h"
#include <cstdlib>
#include <cstring>
#include <libgen.h>

/* Dirty macros for a non-fall-through switch; CASE(b) takes a string
   of integer */
#define SWITCH(a) if(0)
#define CASE(b) } else if(!strcmp(basename(argv[0]), b)) {
#define DEFAULT } else {

int main(int argc, char **argv)
{
	/* Choose a numerical scheme according to the program name */
	void (*scheme)(data *, real) = &Euler;
	SWITCH(basename(argv[0])) {
		CASE("Euler") scheme = &Euler;
		CASE("DK")    scheme = &DK;
		CASE("KD")    scheme = &KD;
		CASE("DKD")   scheme = &DKD;
		CASE("KDK")   scheme = &KDK;
	}

	real dt = argc > 1 ? atof(argv[1]) : 0.0;
	if(dt <= 0.0) {
		printf("usage: %s [step_size] < input_file\n", argv[0]);
		return 0;
	}

	FILE *f = argc > 2 ? fopen(argv[argc-1], "r") : NULL;
	data *d = input(f ? f : stdin);

	for(size_t h = 0; h < 6283; ++h) {
		scheme(d, dt);
		output(stdout, d, argv[0], dt);
	}

	return 0;
}
