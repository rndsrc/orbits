#include "orbits.h"
#include <cstdlib>
#include <unistd.h>

#define INIT_M  64
#define LINE_SZ 1024

data *input(FILE *f)
{
	data *d = (data *)malloc(sizeof(data) + sizeof(particle) * INIT_M);
	d->n = 0;
	d->m = INIT_M;

	if(isatty(fileno(f)))
		printf("Please input initial conditions [end with Ctr+D]:\n");

	char line[LINE_SZ];
	while(fgets(line, sizeof(line), f)) {
		if(line[0] == '#')
			continue;
		if(d->n >= d->m)
			d = (data *)realloc(d, sizeof(data) +
			                       sizeof(particle) * (d->m *= 2));
		sscanf(line, "%lf %lf %lf %lf %lf %lf %lf",
		       &d->p[d->n].m,
		       &d->p[d->n].r.x, &d->p[d->n].r.y, &d->p[d->n].r.z,
		       &d->p[d->n].u.x, &d->p[d->n].u.y, &d->p[d->n].u.z);
		++d->n;
	}

	return d;
}
