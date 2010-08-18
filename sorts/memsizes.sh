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
set title "Problem size vs Page Faults\\nEach line holds available memory constant"
set yrange [0:1000000]
set xrange [0:1100]
set style line 1 linewidth 2 pt 4 linetype 3 ps 2
set style line 2 linewidth 2 linetype 10 ps 2
set xlabel "Problem size in megabytes"
set ylabel "Number of major page faults"
set border 0
set key below
set grid
set mxtics 
set mytics 
EOF

if [ -n "$OUTPUT" ]
then
        echo set output \"${OUTPUT}\"
fi

( echo plot
KEYED=
for i in heapsortdata/memsizes/*.dat 
do
        echo $i | sed -e 's/^/\\"/' -e 's/$/\\"/g'
        echo with linespoints ls 1
        if [ ${KEYED}z = z ]
        then
                KEYED=x
                echo title \\\"Heapsort\\\"
        else
                echo notitle
        fi
        echo ,
done

KEYED=
for i in mergesortdata/memsizes/*.dat 
do
       echo $i | sed -e 's/^/\\"/' -e 's/$/\\"/g'
       echo with linespoints ls 2
       if [ ${KEYED}z = z ]
       then
               KEYED=x
               echo title \\\"Mergesort\\\"
       else
               echo notitle
       fi
       echo ,
done
) | xargs echo | sed -e 's/,$//'
