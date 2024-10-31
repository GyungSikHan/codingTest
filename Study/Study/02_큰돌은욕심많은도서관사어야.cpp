#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> times;
int Count = -987654321;

void DFS(int a, int count)
{
	if(a >= times.size() - 1)
	{
		Count = max(Count, count);
		return;
	}
	for (int i = 1; i < times.size(); i++)
	{
		if(a+i < times.size())
		{
			if (times[a].second <= times[a + i].first)
				DFS(a+i, count + 1);
		}
	}
}

int main()
{
	cin >> n;
	times.resize(n, {0,0});
	for (int i = 0; i < n; i++)
		cin >> times[i].first >> times[i].second;

	sort(times.begin(), times.end());
	for (int i = 0; i < times.size(); i++)
		DFS(i,1);

	cout << Count << endl;
}