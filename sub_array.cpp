#include "utilities.h"

using namespace std;

int findMaxSumSubArray(int *a, int n, int &count_compare, int &count_assign)
{

    int best = INT_MIN;
    int sum = 0;
    count_assign = 2; // 2a
    count_compare = 0;

    for (int i = 0; ++count_compare && i < n; ++count_assign, i++) // (n+1)c, na
    {
        sum = max(a[i], sum + a[i]);
        count_compare++;
        count_assign++;

        best = max(best, sum);
        count_compare++;
        count_assign++;

        // 2na 2nc
        /*
        assign = 2a + na + 2na = (3n + 2)a
        compare = (n+1)c + 2nc = (3n + 1)c
        */
    }

    return best;
}

int main()
{
    int N_size[] = {10, 100, 1000, 10000, 100000};

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        int count_compare = 0;
        int count_assign = 0;

        int *a = generateA(N_size[i]);
        printf("With n = %d:\n", N_size[i]);
        int max_sum_sub_array = findMaxSumSubArray(a, N_size[i], count_compare, count_assign);
        printf("Max of sub array is: %d, with %d assign, and %d comparision\n", max_sum_sub_array, count_assign, count_compare);

        delete[] a;
    }

    return 0;
}