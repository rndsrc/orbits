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
