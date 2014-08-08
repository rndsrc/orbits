#include "orbits.h"
#include <cstdlib>

void DKD(data *d, real dt)
{
	static vector *a = (vector *)malloc(sizeof(vector) * d->n);

	size_t    n = d->n;
	particle *p = d->p;

	real dt2 = dt / 2;

	for(size_t i = 0; i < n; ++i) {
		p[i].r.x += dt2* p[i].u.x;
		p[i].r.y += dt2* p[i].u.y;
		p[i].r.z += dt2* p[i].u.z;
	}

	acc(a, p, n);

	for(size_t i = 0; i < n; ++i) {
		p[i].u.x += dt * a[i].  x;
		p[i].u.y += dt * a[i].  y;
		p[i].u.z += dt * a[i].  z;
		p[i].r.x += dt2* p[i].u.x;
		p[i].r.y += dt2* p[i].u.y;
		p[i].r.z += dt2* p[i].u.z;
	}
}
