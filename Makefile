orbits: *.h *.c[cu]
	g++ *.c[cu] -Wextra -O3 -lm -o orbits

clean:
	rm -f orbits *~
