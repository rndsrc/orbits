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
#include <cstring>
#include <dlfcn.h>

scheme *get_scheme(const char *path)
{
	const char *name = strrchr(path, '/');

	void   *ego = dlopen(NULL, RTLD_LAZY);
	scheme *scm = (scheme *)dlsym(ego, name ? name + 1 : path);

	return scm ? scm : &Euler;
}

size_t get_factor(const char *path)
{
	const char *name = strrchr(path, '/');

	if(strcmp("ChinC", name ? name + 1 : path))
		return 5;
	else
		return 1; // ChinC uses almost 6 times more FLOP than
	                  // all other algorithms.  However it uses
	                  // only 3 times more bandwidth.
}
