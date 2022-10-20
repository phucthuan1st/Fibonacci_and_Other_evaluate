#include "utilities.h"

int rand10000()
{
    return -10000 + ((rand() % 1000) * (rand() % 2000)) % 20000;
}

int *generateA(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand10000();
    }
    return arr;
}