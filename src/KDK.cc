#include "orbits.h"
#include <cstdlib>

void KDK(data *d, real dt)
{
	static vector *a = NULL;
	if(!a) {
		a = (vector *)malloc(sizeof(vector) * d->n);
		acc(a, d->p, d->n);
	}

	size_t    n = d->n;
	particle *p = d->p;

	real dt2 = dt / 2;

	for(size_t i = 0; i < n; ++i) {
		p[i].u.x += dt2* a[i].  x;
		p[i].u.y += dt2* a[i].  y;
		p[i].u.z += dt2* a[i].  z;
		p[i].r.x += dt * p[i].u.x;
		p[i].r.y += dt * p[i].u.y;
		p[i].r.z += dt * p[i].u.z;
	}

	acc(a, p, n);

	for(size_t i = 0; i < n; ++i) {
		p[i].u.x += dt2* a[i].  x;
		p[i].u.y += dt2* a[i].  y;
		p[i].u.z += dt2* a[i].  z;
	}
}
