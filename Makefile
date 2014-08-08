orbits: *.h *.c[cu]
	g++ *.c[cu] -O3 -lm -o orbits

clean:
	rm -f orbits *~
