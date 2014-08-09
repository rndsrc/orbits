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

typedef void (scheme)(data *, real);

scheme *get_scheme(const char *);
size_t  get_factor(const char *);

void acc (vector *, const particle *, size_t);
void acc2(vector *, const particle *, size_t, real);
real energy(const particle *, size_t);

data *input(FILE *);
void output(FILE *, const data *, const char *, const char *);

extern "C" {
	// 1st order schemes
	void Euler(data *, real);
	void DK   (data *, real);
	void KD   (data *, real);
	// 2nd order schemes
	void DKD  (data *, real);
	void KDK  (data *, real);
	// 4th order schemes
	void ChinC(data *, real);
}

#endif // ORBITS_H
