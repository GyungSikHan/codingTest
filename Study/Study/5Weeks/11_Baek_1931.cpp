#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, s, e;
vector<pair<int, int>>v;

int ret;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({ e,s });
	}
	sort(v.begin(), v.end());

	int count = {};
	int end = -1;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second >= end)
		{
			count++;
			end = v[i].first;
		}
	}

	cout << count << endl;
}