// Copyright (C) 2014 Chi-kwan Chan
// Copyright (C) 2014 Steward Observatory
//
// This file is part of orbits.
//
// Orbits is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Orbits is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Orbits.  If not, see <http://www.gnu.org/licenses/>.

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
			real f  = p[j].m / (rr * rr * sqrt(rr));
			real fx = f * (a[j].x - a[i].x);
			real fy = f * (a[j].y - a[i].y);
			real fz = f * (a[j].z - a[i].z);
			real df = dx * fx + dy * fy + dz * fz;
			real rr3= rr / 3.0;
			b[i].x += dx * df - fx * rr3;
			b[i].y += dy * df - fy * rr3;
			b[i].z += dz * df - fz * rr3;
		} // 35 FLOP + 1 sqrt()
	}

	real h = -dt * dt / 8.0;
	for(size_t i = 0; i < n; ++i) {
		a[i].x += h * b[i].x;
		a[i].y += h * b[i].y;
		a[i].z += h * b[i].z;
	}
}
