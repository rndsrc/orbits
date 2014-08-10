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

void acc(vector *a, const particle *p, size_t n)
{
	for(size_t i = 0; i < n; ++i) {
		a[i].z = a[i].y = a[i].x = 0.0;
		for(size_t j = 0; j < n; ++j) if(j != i) {
			real dx = p[j].r.x - p[i].r.x;
			real dy = p[j].r.y - p[i].r.y;
			real dz = p[j].r.z - p[i].r.z;
			real rr = dx * dx + dy * dy + dz * dz;
			real f  = p[j].m / (rr * sqrt(rr));
			a[i].x += f * dx;
			a[i].y += f * dy;
			a[i].z += f * dz;
		} // 16 FLOP + 1 sqrt()
	}
}
