#include "orbits.h"
#include <cstdlib>

#define INIT_M  64
#define LINE_SZ 1024

data *input(FILE *f)
{
	data *d = (data *)malloc(sizeof(data) + sizeof(particle) * INIT_M);
	d->n = 0;
	d->m = INIT_M;

	char line[LINE_SZ];
	while(fgets(line, sizeof(line), f)) {
		if(line[0] == '#' || line[0] == '\n')
			continue;
		if(d->n >= d->m)
			d = (data *)realloc(d, sizeof(data) +
			                       sizeof(particle) * (d->m *= 2));
		sscanf(line, "%lg %lg %lg %lg %lg %lg %lg",
		       &d->p[d->n].m,
		       &d->p[d->n].r.x, &d->p[d->n].r.y, &d->p[d->n].r.z,
		       &d->p[d->n].u.x, &d->p[d->n].u.y, &d->p[d->n].u.z);
		++d->n;
	}

	if(d->n)
		return d;
	else {
		free(d);
		return NULL;
	}
}
