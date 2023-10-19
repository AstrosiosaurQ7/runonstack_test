#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int runonstack(int (*func)(int), int arg, long *stack);
int test(int a)
{
    printf("in test %d\n", a);
    if (--a > 0)
    {
        printf("returned %d\n", test(a));
    }
    return a;
}

long stack[1024];
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: test count\n");
        exit(1);
    }

    int count = atoi(argv[1]);
    int ret = runonstack(test, count, &stack[1023]);
    printf("runonstack returned %d\n", ret);
    return 0;
}

// int runonstack(int (*func)(int), int arg, long *stack)
// {
//     return (*func)(arg);
// }
