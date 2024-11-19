#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, dead, cup;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>>pq;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> dead >> cup;
		v.push_back({dead,cup});
	}
	sort(v.begin(), v.end());

	int result{};
	for (int i = 0; i < v.size(); i++)
	{
		result += v[i].second;
		pq.push(v[i].second);
		if(pq.size() > v[i].first)
		{
			result -= pq.top();
			pq.pop();
		}
	}
	cout << result << endl;
}