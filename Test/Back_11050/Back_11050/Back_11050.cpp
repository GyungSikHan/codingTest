﻿#include <iostream>

using namespace std;

int Factorial(int a)
{
	int data = 1;
	for (int i = 1; i <= a; i++)
		data *= i;

	return data;
}

int main()
{
	int n{}, k{};
	cin >> n >> k;
	int result = Factorial(n) / (Factorial(n - k) * Factorial(k));

	cout << result << endl;
}