#include "fibonacci.h"
#include <ctime>

int fibonacci_recursion(int n, int &count_compare)
{
    if (++count_compare && n <= 1)
        return 1;

    return fibonacci_recursion(n - 1, count_compare) + fibonacci_recursion(n - 2, count_compare);
}

int fibonacci_loop(int n, int &count_assign)
{
    count_assign = 0;

    if (n <= 1)
        return 1;

    int last = 1;
    count_assign++;
    int nextToLast = 1;
    count_assign++;
    int answer = 1;
    count_assign++;

    for (int i = 2; i <= n; count_assign++, i++)
    {
        answer = last + nextToLast;
        count_assign++;
        nextToLast = last;
        count_assign++;
        last = answer;
        count_assign++;
    }

    return answer;
}

int main()
{
    system("cls");

    int a[] = {5, 15, 25, 35, 40};

    for (auto &element : a)
    {
        int count_compare = 0;
        cout << "Fibonacci " << element << " is " << fibonacci_recursion(element, count_compare) << endl;
        cout << "Number of compare: " << count_compare << endl;
    }

    cout << "--------------------------------" << endl;

    for (auto &element : a)
    {
        int count_assign = 0;
        cout << "Fibonacci " << element << " is " << fibonacci_loop(element, count_assign) << endl;
        cout << "Number of assign: " << count_assign << endl;
    }
}