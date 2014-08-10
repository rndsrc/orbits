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
