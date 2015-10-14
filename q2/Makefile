CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run: $(EXEC)
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf stat --repeat 5 -e cache-misses,cache-references,instructions,cycles ./iterative
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf  stat --repeat 5 -e cache-misses,cache-references,instructions,cycles ./recursive
	
clean:
	$(RM) $(EXEC) *.o perf.*
