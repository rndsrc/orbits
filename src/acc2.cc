#include "orbits.h"
#include <cmath>

void acc2(vector *a, const particle *p, size_t n, real dt)
{
	const real h = dt * dt / 24.0;

	for(size_t i = 0; i < n; ++i) {
		real ax  = 0.0, ay  = 0.0, az  = 0.0;
		real axx = 0.0, ayy = 0.0, azz = 0.0;
		real axy = 0.0, ayz = 0.0, azx = 0.0;

		for(size_t j = 0; j < n; ++j) if(j != i) {
			real dx = p[j].r.x - p[i].r.x;
			real dy = p[j].r.y - p[i].r.y;
			real dz = p[j].r.z - p[i].r.z;
			real rr = dx * dx + dy * dy + dz * dz;

			real f  = p[j].m / (rr * sqrt(rr));
			real g  = -3.0 * f / rr;

			ax  += f * dx;
			ay  += f * dy;
			az  += f * dz;

			axx += g * dx * dx - f;
			ayy += g * dy * dy - f;
			azz += g * dz * dz - f;

			axy += g * dx * dy;
			ayz += g * dy * dz;
			azx += g * dz * dx;
		}

		a[i].x = ax - h * (ax * axx + ay * axy + az * azx);
		a[i].y = ay - h * (ax * axy + ay * ayy + az * ayz);
		a[i].z = az - h * (ax * azx + ay * ayz + az * azz);

		// 60 FLOP + 1 sqrt()
	}
}
