#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mergesort(int array[], long lo, long hi)
{
    int *spare;
    int ssize;
    long sindex, hindex, i;
    long mid;
    if (lo+1 >= hi) return; // Base case

    mid = (lo + hi) / 2;  // Recurse on each half
    mergesort(array, lo, mid);
    mergesort(array, mid, hi);

    ssize = mid-lo; // Only copy out the first half
    spare = (int *)malloc(ssize * sizeof(int));
    memcpy(spare, &(array[lo]), ssize * sizeof(int));

    sindex = 0;
    hindex = mid;
    i = lo;
    
    while (sindex < ssize && hindex < hi) { // Merge
        if (spare[sindex] < array[hindex])
            array[i++] = spare[sindex++];
        else
            array[i++] = array[hindex++]; // The 2nd half is in-place
    }

    while (sindex < ssize) array[i++] = spare[sindex++];

    free(spare);
}

#define Mb (1024*1024)

int main(int argc, char **argv)
{
        int *array, i, repeats;
        long SIZE;
        SIZE = atol(argv[1])*Mb/sizeof(int);
	printf("Allocated %ld ints\n", SIZE);

        repeats = atoi(argv[2]);

        array = malloc(SIZE*sizeof(int));
        fprintf(stderr, "%p\n", array);
        
        while (repeats--> 0) { 
                for (i = 0; i < SIZE; i++) {
                        array[i] = i*7 % SIZE;
                }

                mergesort(array, 0, SIZE);
        }

        free(array);

        return 0;
}
