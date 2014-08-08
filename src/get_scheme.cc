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
