#ifndef ORBITS_H
#define ORBITS_H

typedef double real;

typedef struct {
	real x, y, z;
} vector;

typedef struct {
	real   m;
	vector r, u;
} particle;

#endif // ORBITS_H
