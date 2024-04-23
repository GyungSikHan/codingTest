#include <iostream>
using namespace std;

int main()
{
	int n{}, a{};
	long long min = 1000001, max = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (max < a)
			max = a;
		if (min > a)
			min = a;
	}

	cout << min * max << endl;
}