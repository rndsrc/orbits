orbits: src/*.h src/*.c[cu]
	@mkdir -p bin
	g++ src/*.c[cu] -Wextra -O3 -lm -o bin/orbits

clean:
	rm -f bin/orbits *~
	@if [ -z "`ls bin 2>&1`" ]; then rmdir bin; fi
