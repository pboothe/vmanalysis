HEAPDATA=$(addprefix heapsortdata/,$(addsuffix .dat,$(shell seq -w 128 128 2048)))
QUICKDATA=$(addprefix quicksortdata/,$(addsuffix .dat,$(shell seq -w 128 128 4095)))

all: heapsort quicksort memkiller $(HEAPDATA) $(QUICKDATA)

heapsortdata/%.dat: heapsort
	time ./heapsort $* 2>> $@

heapsort: heapsort.c
	\rm -f $(HEAPDATA)
	gcc -g -l bsd $< -o $@

quicksort: quicksort.c
	\rm -f $(QUICKDATA)
	gcc -g $< -o $@

memkiller: memkiller.c
	gcc -g $< -o $@
