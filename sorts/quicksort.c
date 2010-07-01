#include <stdio.h>
#include <stdlib.h>

int cmp(const void *i, const void *j)
{
        if (*((int*)i) == *((int*)j)) return 0;
        else return *((int*)i) < *((int*)j) ? 1 : -1;
}

#define Mb (1024*1024)

int main(int argc, char **argv)
{
        int *array, i, SIZE;
        SIZE = atoi(argv[1])*Mb/sizeof(int);

        array = malloc(sizeof(int) * SIZE);
        for (i = 0; i < SIZE; i++) array[i] = i*7 % SIZE;

        qsort(array, SIZE, sizeof(int), &cmp);

        return 0;
}
