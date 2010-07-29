MEM=$(shell cat /proc/meminfo | grep MemTotal | awk '{ print $$2 }')
MAXMEM=$(shell (echo "(2*$(MEM))/1024 + 64" | bc; echo 512) | sort -n | tail -n 1 )
HEAPDATA=$(addprefix heapsortdata/$(MEM)-,$(addsuffix .dat,$(shell seq -w 64 64 $(MAXMEM))))
MERGEDATA=$(addprefix heapsortdata/$(MEM)-,$(addsuffix .dat,$(shell seq -w 64 64 $(MAXMEM))))

all: heapsort mergesort memkiller $(HEAPDATA) $(MERGEDATA)

heapsortdata/$(MEM)-%.dat: heapsort
	/usr/bin/time ./heapsort $* 1 2> $@

mergesortdata/$(MEM)-%.dat: mergesort
	/usr/bin/time ./mergesort $* 1 2> $@

heapsort: heapsort.c
	gcc -g -l bsd $< -o $@

mergesort: mergesort.c
	gcc -g -l bsd $< -o $@

clean:
	\rm -Rf heapsort mergesort $(HEAPDATA) $(MERGEDATA)
