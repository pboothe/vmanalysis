#!/bin/bash

TERM=png
OUTPUT=
if [ -n "$1" ]
then
        TERM=$1
        OUTPUT=$2
fi

cat - <<EOF
set term ${TERM}
set title "Heapsort is bad and gets worse as problems grow\nEach line holds available memory constant"

set xlabel "Problem size in megabytes"
set ylabel "Ratio of Heapsort page faults to Mergesort page faults"
set border 0
set key below
set grid
set mxtics 
set mytics 
set yrange [0:20]
set key off
EOF

if [ -n "$OUTPUT" ]
then
        echo set output \"${OUTPUT}\"
fi

for i in `seq 1 30`
do
        echo set style line $i linewidth 2 ps 2
done

c=1
for i in ratios/*.dat
do
        echo \\\"$i\\\" using 1:\\\(\$3/\$2\\\) with linespoints ls $c,
        c=$[ $c + 1 ]
done | xargs echo plot | sed -e 's/,$//'
