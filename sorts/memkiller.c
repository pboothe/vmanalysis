#include <stdlib.h>
#include <time.h>

#define Mb (1024*1024)

int main(int argc, char **argv)
{
        long long size;
        char *mem;
        size = atol(argv[1]) * Mb;

        mem = (char *)malloc(size * sizeof(char));

        srandom(time(NULL));
        while (1) {
                mem[random() % size] = (char)(random() % 256);
        }
}
