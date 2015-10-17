CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = main
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run: $(EXEC)
	 ./$(EXEC)
	gnuplot graph.dem
	
clean:
	$(RM) $(EXEC) *.o perf.*
