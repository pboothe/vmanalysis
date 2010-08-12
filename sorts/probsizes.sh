#!/bin/bash

cat - <<EOF
set term png
set title "Available Memory vs Page Faults\\nEach line holds problem size constant"
set yrange [0:1000000]
set xrange [0:520000]
set style line 1 linewidth 2 pt 4 linetype 3 ps 2
set style line 2 linewidth 2 linetype 10 ps 2
set xlabel "Available memory in kilobytes"
set ylabel "# of major page faults"
set border 0
set key below
set grid
set mxtics 
set mytics 
EOF

( echo plot
KEYED=
for i in heapsortdata/probsizes/*.dat 
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
for i in mergesortdata/probsizes/*.dat 
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
