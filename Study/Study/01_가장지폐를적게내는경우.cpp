#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, Count;
vector<pair<int, int>> v = { {10000,5},{5000,5},{1000,5},{100,5} };

int main()
{
	cin >> n;

	sort(v.rbegin(), v.rend());
	for (auto a : v)
	{
		while (n >= a.first && a.second > 0)
		{
			n -= a.first;
			a.second--;
			Count++;
		}
	}
	cout << Count << endl;
}