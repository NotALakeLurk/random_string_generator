CFLAGS = -Wall -Wextra
CC = gcc
VPATH = src:build

# MAKE STUFF? 

build/bin/random_string_generator: main.o string_gen.o
	mkdir -p build/bin
	$(CC) $(CFLAGS) $? -o $@

build/main.o: main.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $? -o $@
	
build/string_gen.o: string_gen.c
	$(CC) $(CFLAGS) -c $? -o $@

# MACRO SHI

# Clean up built object files (not linked application)
.PHONY = clean
clean:
	rm -rvf build
	
# Compile (maybe not always?) and run the app
.PHONY = run
run: clean build/bin/random_string_generator
	./build/bin/random_string_generator
