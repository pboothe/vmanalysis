HEAPDATA=$(addprefix heapsortdata/,$(addsuffix .dat,16 32 48 64 80 96 128))
#QUICKDATA=$(addprefix quicksortdata/,$(addsuffix .dat,$(shell seq -w 128 128 4095)))

all: heapsort quicksort memkiller $(HEAPDATA) 

heapsortdata/%.dat: heapsort
	mkdir -p $@
	/usr/bin/time -l ./heapsort $* 1 > $@/$*-1

heapsort: heapsort.c
	gcc -g $< -o $@

quicksort: quicksort.c
	gcc -g $< -o $@

memkiller: memkiller.c
	gcc -g $< -o $@

clean:
	\rm -Rf heapsort quicksort memkiller $(HEAPDATA) $(QUICKDATA) 
