#include "orbits.h"
#include <cstdlib>
#include <cmath>

const real eps = 1.0e-32;

int main(int argc, char **argv)
{
	real dt = argc > 1 ? atof(argv[1]) : 0.0;
	if(dt <= 0.0) {
		printf("usage: %s [step_size] < input_file\n", argv[0]);
		return 0;
	}

	FILE *f = argc > 2 ? fopen(argv[argc-1], "r") : NULL;
	data *d = input(f ? f : stdin);

	vector *a = (vector *)malloc(sizeof(vector) * d->n);
	for(size_t h = 0; h < 6283; ++h) {
		size_t    n = d->n;
		particle *p = d->p;

		for(size_t i = 0; i < n; ++i) {
			a[i].z = a[i].y = a[i].x = 0.0;
			for(size_t j = 0; j < n; ++j) {
				real dx = p[j].r.x - p[i].r.x;
				real dy = p[j].r.y - p[i].r.y;
				real dz = p[j].r.z - p[i].r.z;
				real rr = dx * dx + dy * dy + dz * dz + eps;
				real f  = p[j].m / (rr * sqrt(rr));
				a[i].x += f * dx;
				a[i].y += f * dy;
				a[i].z += f * dz;
			}
		}

		for(size_t i = 0; i < n; ++i) {
			p[i].r.x += dt * p[i].u.x;
			p[i].r.y += dt * p[i].u.y;
			p[i].r.z += dt * p[i].u.z;
			p[i].u.x += dt * a[i]  .x;
			p[i].u.y += dt * a[i]  .y;
			p[i].u.z += dt * a[i]  .z;
		}
		output(stdout, d, argv[0], dt);
	}
	free(a);

	return 0;
}
