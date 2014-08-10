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
#include <cstdlib>

void Euler(data *d, real dt)
{
	static vector *a = (vector *)malloc(sizeof(vector) * d->n);

	size_t    n = d->n;
	particle *p = d->p;

	acc(a, p, n);

	for(size_t i = 0; i < n; ++i) {
		p[i].r.x += dt * p[i].u.x;
		p[i].r.y += dt * p[i].u.y;
		p[i].r.z += dt * p[i].u.z;
		p[i].u.x += dt * a[i]  .x;
		p[i].u.y += dt * a[i]  .y;
		p[i].u.z += dt * a[i]  .z;
	}
}
