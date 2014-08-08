#include "orbits.h"
#include <cstdlib>
#include <unistd.h>

void output(FILE *f, const data *d, const char *cmd, const char *fmt)
{
	if(fmt)
		fprintf(f, "#!%s %s\n", cmd, fmt);
	else
		fprintf(f, "#!%s\n", cmd);

	for(size_t i = 0; i < d->n; ++i)
		fprintf(f, "%.12g\t%.12g\t%.12g\t%.12g\t%.12g\t%.12g\t%.12g\n",
		        d->p[i].m,
		        d->p[i].r.x, d->p[i].r.y, d->p[i].r.z,
		        d->p[i].u.x, d->p[i].u.y, d->p[i].u.z);
}
