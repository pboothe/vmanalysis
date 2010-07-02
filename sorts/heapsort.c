#include <stdio.h>
#include <stdlib.h>
#include <bsd/stdlib.h>

int cmp(const void *i, const void *j)
{
        if (*((int*)i) == *((int*)j)) return 0;
        else return *((int*)i) < *((int*)j) ? 1 : -1;
}

#define Mb (1024*1024)

int main(int argc, char **argv)
{
        int *array, i, repeats;
        long SIZE;
        SIZE = atol(argv[1])/sizeof(int)*Mb;
        repeats = atoi(argv[2]);

        array = malloc(SIZE*sizeof(int));
        
        while (repeats--> 0) { 
                for (i = 0; i < SIZE; i++) array[i] = i*7 % SIZE;

                heapsort(array, SIZE, sizeof(int), &cmp);
        }

        free(array);

        return 0;
}
