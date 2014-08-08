#ifndef ORBITS_H
#define ORBITS_H

#include <cstdio> /* for size_t and FILE */

typedef double real;

typedef struct {
	real x, y, z;
} vector;

typedef struct {
	real   m;
	vector r, u;
} particle;

typedef struct {
	size_t n, m;
	particle  p[];
} data;

data *input(FILE *);
void output(FILE *, const data *, const char *, real);

void acc(vector *, const particle *, size_t);

void Euler(data *, real);
void DK   (data *, real);
void KD   (data *, real);

#endif // ORBITS_H
