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
        int *array, i;
        long SIZE;
        SIZE = atol(argv[1])/sizeof(int)*Mb;

        array = malloc(SIZE*sizeof(int));
        for (i = 0; i < SIZE; i++) array[i] = i*7 % SIZE;

        heapsort(array, SIZE, sizeof(int), &cmp);

        return 0;
}
