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
#include <unistd.h>

void output(FILE *f, const data *d, const char *cmd, const char *fmt)
{
	if(fmt)
		fprintf(f, "#!%s %s\n", cmd, fmt);
	else
		fprintf(f, "#!%s\n", cmd);

	for(size_t i = 0; i < d->n; ++i)
		fprintf(f, "%.16g\t%.16g\t%.16g\t%.16g\t%.16g\t%.16g\t%.16g\n",
		        d->p[i].m,
		        d->p[i].r.x, d->p[i].r.y, d->p[i].r.z,
		        d->p[i].u.x, d->p[i].u.y, d->p[i].u.z);
}
