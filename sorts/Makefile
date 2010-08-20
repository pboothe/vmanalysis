MEM=$(shell cat /proc/meminfo | grep MemTotal | awk '{ print $$2 }')
MAXMEM=$(shell (echo "(2*$(MEM))/1024 + 64" | bc; echo 512) | sort -n | tail -n 1 )
HEAPDATA=$(addprefix heapsortdata/$(MEM)-,$(addsuffix .dat,$(shell seq -w 64 64 $(MAXMEM))))
MERGEDATA=$(addprefix mergesortdata/$(MEM)-,$(addsuffix .dat,$(shell seq -w 64 64 $(MAXMEM))))

all: processeddata

processeddata: memsizes.pdf ratios.pdf

datfiles: 
	./makedats.sh mergesortdata
	./makedats.sh heapsortdata

memsizes.pdf: memsizes.sh
	./memsizes.sh "epslatex color" memsizes.tex | gnuplot 
	epstopdf memsizes.eps
	rm -f memsizes.png

memsizes.png: memsizes.sh
	./memsizes.sh | gnuplot > $@

probsizes.png: probsizes.sh
	./probsizes.sh | gnuplot > $@

ratios.pdf: ratios.sh
	./ratios.sh "epslatex color" ratios.tex | gnuplot 
	epstopdf ratios.eps
	rm -f ratios.png

ratios.png: ratios.sh
	./ratios.sh | gnuplot > $@
        
heapdata: $(HEAPDATA) heapsort

mergedata: $(MERGEDATA) mergesort

heapsortdata/$(MEM)-%.dat: heapsort
	/usr/bin/time ./heapsort $* 1 2> $@

mergesortdata/$(MEM)-%.dat: mergesort
	/usr/bin/time ./mergesort $* 1 2> $@

heapsort: heapsort.c
	gcc -g -l bsd $< -o $@

mergesort: mergesort.c
	gcc -g $< -o $@

clean:
	\rm -Rf heapsort mergesort $(HEAPDATA) $(MERGEDATA)
