﻿#include <iostream>

using namespace std;

int arr[21];

void Pivo(int n)
{
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
}

int main()
{
	int n{};
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	Pivo(n);

	cout << arr[n] << endl;
}