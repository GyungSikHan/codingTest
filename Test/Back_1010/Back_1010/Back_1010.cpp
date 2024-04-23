#include <iostream>
using namespace std;

int Solution(int n, int m)
{
	int a = 1, b = 1;

	for (int i = m; i > m-n; i--)
	{
		a *= i;
		a /= b;
		b++;
	}

	return a;
}

int main()
{
	int t{};
	int n{}, m{};

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		cout<<Solution(n, m) << endl;
	}
}
