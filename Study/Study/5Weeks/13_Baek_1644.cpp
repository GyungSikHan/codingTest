#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, result;
vector<int> v;

int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		bool b{};
		for (int j = 2;b == false && j <= sqrt(i); j++)
		{
			if (i % j == 0)
				b = true;
		}
		if (b == false)
			v.push_back(i);
	}

	int length = v.size();
	int s{}, e{};
	int sum{};
	while (true)
	{
		if (sum >= n)
			sum -= v[e++];
		else if(s == length)
			break;
		else
			sum += v[s++];

		if (sum == n)
			result++;
	}
	cout << result;
}