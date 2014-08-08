#include "orbits.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc > 1 && !strcmp(argv[1], "--help")) {
		printf("usage: %s [step_size] < input_file\n", argv[0]);
		return 0;
	}

	real dt = argc > 1 ? atof(argv[1]) : 1e-3;
	printf("dt = %g\n", dt);

	if(isatty(fileno(stdin)))
		printf("Please input initial conditions [end by Ctr+D]:\n");

	char line[1024];
	while(fgets(line, sizeof(line), stdin))
		if(line[0] != '#')
			fputs(line, stdout);

	return 0;
}
