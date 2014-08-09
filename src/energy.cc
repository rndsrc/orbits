#include "orbits.h"
#include <cmath>

real energy(const particle *p, size_t n)
{
	real E = 0.0;

	for(size_t i = 0; i < n; ++i) {
		real uu = (p[i].u.x * p[i].u.x +
		           p[i].u.y * p[i].u.y +
		           p[i].u.z * p[i].u.z);
		E += 0.5 * p[i].m * uu;

		for(size_t j = 0; j < i; ++j) {
			real dx = p[j].r.x - p[i].r.x;
			real dy = p[j].r.y - p[i].r.y;
			real dz = p[j].r.z - p[i].r.z;
			real rr = dx * dx + dy * dy + dz * dz;
			E -= p[i].m * p[j].m / sqrt(rr);
		}
	}

	return E;
}
