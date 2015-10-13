CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = main_shf main_asf
all: $(EXEC)

main_shf: main.c
	$(CC) $(CFLAGS_common) -DSHF -o $@ $<

main_asf: main.c
	$(CC) $(CFLAGS_common) -DASF -o $@ $<

run: main_shf main_asf
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf stat -e cache-misses,cache-references,instructions,cycles ./main_shf
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf stat -e cache-misses,cache-references,instructions,cycles ./main_asf
	
clean:
	$(RM) $(EXEC) *.o perf.*
