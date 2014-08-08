#include "orbits.h"
#include <cstdlib>
#include <unistd.h>

void output(const data *d, FILE *f)
{
	for(size_t i = 0; i < d->n; ++i)
		fprintf(f, "%lf %lf %lf %lf %lf %lf %lf\n",
		        d->p[i].m,
		        d->p[i].r.x, d->p[i].r.y, d->p[i].r.z,
		        d->p[i].u.x, d->p[i].u.y, d->p[i].u.z);
}
