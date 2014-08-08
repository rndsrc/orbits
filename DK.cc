#include "orbits.h"
#include <cstdlib>

void DK(data *d, real dt)
{
	static vector *a = (vector *)malloc(sizeof(vector) * d->n);

	size_t    n = d->n;
	particle *p = d->p;

	for(size_t i = 0; i < n; ++i) {
		p[i].r.x += dt * p[i].u.x;
		p[i].r.y += dt * p[i].u.y;
		p[i].r.z += dt * p[i].u.z;
	}

	acc(a, p, n);

	for(size_t i = 0; i < n; ++i) {
		p[i].u.x += dt * a[i].x;
		p[i].u.y += dt * a[i].y;
		p[i].u.z += dt * a[i].z;
	}
}
