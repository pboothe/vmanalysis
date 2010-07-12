#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

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
        struct rlimit limits;
        SIZE = atol(argv[1])/sizeof(int)*Mb;

        repeats = atoi(argv[2]);

        limits.rlim_cur = SIZE*sizeof(int)/2;
        limits.rlim_max = SIZE*sizeof(int)/2;
        if (setrlimit(RLIMIT_RSS, &limits)) {
            perror("setting limits");
            exit(1);
        }

        array = malloc(SIZE);
        if (NULL == array) {
            perror("allocating");
            exit(1);
        }
        fprintf(stderr, "%p\n", array);
        
        while (repeats--> 0) { 
                for (i = 0; i < SIZE; i++) {
                    fprintf(stderr, "%d\n", i);
                    array[i] = i*7 % SIZE;
                }

                heapsort(array, SIZE, sizeof(int), &cmp);
        }

        free(array);

        return 0;
}
