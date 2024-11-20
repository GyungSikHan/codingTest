#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, s, e;
vector<pair<int, int>>v;
//priority_queue<>

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end());

	int ret{};
	for (pair<int, int>iter : v)
	{
		if (ret < iter.first)
			ret = iter.first + iter.second;
		else
			ret += iter.second;
		
	}

	cout << ret << endl;
}