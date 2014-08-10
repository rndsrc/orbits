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

#define INIT_M  64
#define LINE_SZ 1024

data *input(FILE *f)
{
	data *d = (data *)malloc(sizeof(data) + sizeof(particle) * INIT_M);
	d->n = 0;
	d->m = INIT_M;

	char line[LINE_SZ];
	while(fgets(line, sizeof(line), f)) {
		if(line[0] == '#' || line[0] == '\n')
			continue;
		if(d->n >= d->m)
			d = (data *)realloc(d, sizeof(data) +
			                       sizeof(particle) * (d->m *= 2));
		sscanf(line, "%lg\t%lg\t%lg\t%lg\t%lg\t%lg\t%lg",
		       &d->p[d->n].m,
		       &d->p[d->n].r.x, &d->p[d->n].r.y, &d->p[d->n].r.z,
		       &d->p[d->n].u.x, &d->p[d->n].u.y, &d->p[d->n].u.z);
		++d->n;
	}

	if(d->n)
		return d;
	else {
		free(d);
		return NULL;
	}
}
