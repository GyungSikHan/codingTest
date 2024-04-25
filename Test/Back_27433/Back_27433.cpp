﻿#include <iostream>
#include <cmath>
using namespace std;

long long result = 1;

void Factorial(int n)
{
	if (n == 0)
		return;
	result *= n;
	Factorial(n - 1);
}

int main()
{
	int n{  };
	cin >> n;

	Factorial(n);

	cout << result << endl;
}