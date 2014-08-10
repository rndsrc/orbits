#include "orbits.h"
#include <cmath>

void acc2(vector *a, vector *b, const particle *p, size_t n, real dt)
{
	acc(a, p, n);

	for(size_t i = 0; i < n; ++i) {
		b[i].z = b[i].y = b[i].x = 0.0;

		for(size_t j = 0; j < n; ++j) if(j != i) {
			real dx = p[j].r.x - p[i].r.x;
			real dy = p[j].r.y - p[i].r.y;
			real dz = p[j].r.z - p[i].r.z;
			real rr = dx * dx + dy * dy + dz * dz;
			real f  = p[j].m / (rr * sqrt(rr));
			real fx = f * (a[j].x - a[i].x);
			real fy = f * (a[j].y - a[i].y);
			real fz = f * (a[j].z - a[i].z);

			b[i].x += fx * (3 * dx * dx / rr - 1)
				+ fy * (3 * dy * dx / rr    )
				+ fz * (3 * dz * dx / rr    );
			b[i].y += fx * (3 * dx * dy / rr    )
				+ fy * (3 * dy * dy / rr - 1)
				+ fz * (3 * dz * dy / rr    );
			b[i].z += fx * (3 * dx * dz / rr    )
				+ fy * (3 * dy * dz / rr    )
				+ fz * (3 * dz * dz / rr - 1);
		}
	}

	real h = -dt * dt / 24.0;
	for(size_t i = 0; i < n; ++i) {
		a[i].x += h * b[i].x;
		a[i].y += h * b[i].y;
		a[i].z += h * b[i].z;
	}
}
