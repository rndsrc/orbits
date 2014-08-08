#include "orbits.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char **argv)
{
	real dt = argc > 1 ? atof(argv[1]) : 0.0;

	if(dt <= 0.0) {
		printf("usage: %s [step_size] < input_file\n", argv[0]);
		return 0;
	}
	printf("dt = %g\n", dt);

	size_t    n = 0, m = 64;
	particle *p = (particle *)malloc(sizeof(particle) * m);

	if(isatty(fileno(stdin)))
		printf("Please input initial conditions [end by Ctr+D]:\n");
	char line[1024];
	while(fgets(line, sizeof(line), stdin)) {
		if(line[0] == '#')
			continue;
		else
			fputs(line, stdout);

		if(n >= m)
			p = (particle *)realloc(p, sizeof(particle) * (m *= 2));
		sscanf(line, "%lf %lf %lf %lf %lf %lf %lf",
		       &p[n].m,
		       &p[n].r.x, &p[n].r.y, &p[n].r.z,
		       &p[n].u.x, &p[n].u.y, &p[n].u.z);
		++n;
	}

	return 0;
}
