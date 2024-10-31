#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;



int main()
{
	cin >> n;
	v.resize(n, { 0,0 });
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());
	int start = v[0].first;
	int end{};
	int sum{};
	for (int i = 0; i < v.size(); i++)
	{
		if(i+1 != v.size())
		{
			if(v[i].second >= v[i+1].first)
				end = v[i + 1].second;
			else
			{
				sum += end - start;
				start = v[i + 1].first;
			}
		}
		else if(i+1 == v.size())
		{
			end = v[i].second;
			sum += end - start;
		}
	}

	cout << sum << endl;
}