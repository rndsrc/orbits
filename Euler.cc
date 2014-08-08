#include "orbits.h"
#include <cmath>

void acceleration(vector *a, particle *p, size_t n)
{
	const real eps = 1.0e-32;

	for(size_t i = 0; i < n; ++i) {
		a[i].z = a[i].y = a[i].x = 0.0;
		for(size_t j = 0; j < n; ++j) {
			real dx = p[j].r.x - p[i].r.x;
			real dy = p[j].r.y - p[i].r.y;
			real dz = p[j].r.z - p[i].r.z;
			real rr = dx * dx + dy * dy + dz * dz + eps;
			real f  = p[j].m / (rr * sqrt(rr));
			a[i].x += f * dx;
			a[i].y += f * dy;
			a[i].z += f * dz;
		}
	}
}

void Euler(particle *p, vector *a, size_t n, real dt)
{
	acceleration(a, p, n);

	for(size_t i = 0; i < n; ++i) {
		p[i].r.x += dt * p[i].u.x;
		p[i].r.y += dt * p[i].u.y;
		p[i].r.z += dt * p[i].u.z;
		p[i].u.x += dt * a[i]  .x;
		p[i].u.y += dt * a[i]  .y;
		p[i].u.z += dt * a[i]  .z;
	}
}
