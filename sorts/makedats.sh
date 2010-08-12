#!/bin/bash

set -e
cd $1

mkdir -p memsizes
for i in `ls *-*.dat | sed -e 's/-.*//' | sort -un `
do 
    for j in $i-*.dat
    do 
        grep major $j \
            | sed -e 's/major.*//' -e 's/.*(//' \
            | xargs echo ${j/*-/} \
            | sed -e 's/\.dat//' -e 's/^0*//'
    done | sort -nk1 > memsizes/$i.dat 
done

mkdir -p probsizes
for i in `ls *-*.dat | sed -e 's/.*-0*//' -e 's/\.dat//' | sort -un `
do
    for j in *-*$i.dat
    do
        grep major $j \
            | sed -e 's/major.*//' -e 's/.*(//' \
            | xargs echo ${j/-*/} \
            | sed -e 's/\.dat//' -e 's/^0*//'
    done | sort -nk1 > probsizes/$i.dat
done

cd ..
mkdir -p ratios
for i in mergesortdata/memsizes/*.dat
do
        (
                echo "# Memory Mergesort Heapsort"
                join $i ${i/merge/heap} 
        ) > ratios/`basename $i`
done
