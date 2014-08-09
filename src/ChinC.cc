#include "orbits.h"
#include <cstdlib>

void ChinC(data *d, real dt)
{
	static vector *a = NULL;
	if(!a)
		a = (vector *)malloc(sizeof(vector) * d->n);

	size_t    n = d->n;
	particle *p = d->p;

	real dt_6 = dt     / 6.0;
	real dt38 = dt * 3 / 8.0;
	real dt_3 = dt     / 3.0;
	real dt_4 = dt     / 4.0;

	for(size_t i = 0; i < n; ++i) {
		p[i].r.x += dt_6 * p[i].u.x;
		p[i].r.y += dt_6 * p[i].u.y;
		p[i].r.z += dt_6 * p[i].u.z;
	}

	acc(a, p, n);
	for(size_t i = 0; i < n; ++i) {
		p[i].u.x += dt38 * a[i].x;
		p[i].u.y += dt38 * a[i].y;
		p[i].u.z += dt38 * a[i].z;
		p[i].r.x += dt_3 * p[i].u.x;
		p[i].r.y += dt_3 * p[i].u.y;
		p[i].r.z += dt_3 * p[i].u.z;
	}

	acc2(a, p, n, dt);
	for(size_t i = 0; i < n; ++i) {
		p[i].u.x += dt_4 * a[i].x;
		p[i].u.y += dt_4 * a[i].y;
		p[i].u.z += dt_4 * a[i].z;
		p[i].r.x += dt_3 * p[i].u.x;
		p[i].r.y += dt_3 * p[i].u.y;
		p[i].r.z += dt_3 * p[i].u.z;
	}

	acc(a, p, n);
	for(size_t i = 0; i < n; ++i) {
		p[i].u.x += dt38 * a[i].x;
		p[i].u.y += dt38 * a[i].y;
		p[i].u.z += dt38 * a[i].z;
		p[i].r.x += dt_6 * p[i].u.x;
		p[i].r.y += dt_6 * p[i].u.y;
		p[i].r.z += dt_6 * p[i].u.z;
	}
}
