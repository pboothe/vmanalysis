MEM=$(shell cat /proc/meminfo | grep MemTotal | awk '{ print $$2 }')
HEAPDATA=$(addprefix heapsortdata/$(MEM)-,$(addsuffix .dat,$(shell seq -w 16 16 1024)))

all: heapsort quicksort memkiller $(HEAPDATA) 

heapsortdata/$(MEM)-%.dat: heapsort
	/usr/bin/time ./heapsort $* 1 2> $@

heapsort: heapsort.c
	gcc -g -l bsd $< -o $@

quicksort: quicksort.c
	gcc -g $< -o $@

memkiller: memkiller.c
	gcc -g $< -o $@

clean:
	\rm -Rf heapsort quicksort memkiller $(HEAPDATA) 
