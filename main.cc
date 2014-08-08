#include "orbits.h"
#include <cstring>
#include <cstdio>

int main(int argc, char **argv)
{
	if(argc > 1 && !strcmp(argv[1], "--help"))
		printf("usage: %s [step_size] < input_file\n", argv[0]);

	return 0;
}
