orbits: src/*.h src/*.c[cu]
	g++ src/*.c[cu] -Wextra -O3 -rdynamic -lm -ldl -o bin/orbits
	@for p in src/[[:upper:]]*.cc; do \
		ln -sf orbits bin/$${p:4:$${#p}-7}; \
	done

clean:
	@for p in src/[[:upper:]]*.cc; do \
		rm -f bin/$${p:4:$${#p}-7}; \
	done
	@rm -f bin/orbits */*~
