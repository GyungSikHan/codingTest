﻿#include <iostream>

using namespace std;

int n;
int Count = 1;
int Count2;
int f[41];
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1; 
    else
    {
        Count++;
        return (fib(n - 1) + fib(n - 2));
    }
    
}

int fibonacci(int n)
{
    f[1] = 1;
	f[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        Count2++;
        f[i] = f[i - 1] + f[i - 2];
    }

	return f[n];
}

int main()
{
    cin >> n;
    fib(n);
    fibonacci(n);

    cout << Count << endl;
    cout << Count2 << endl;
}