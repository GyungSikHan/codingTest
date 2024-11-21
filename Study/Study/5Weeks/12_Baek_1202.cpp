#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long n, k, m, v, c, result;
vector<pair<long long, long long>> crestal;
vector<long long> back;
priority_queue<long long> pq;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		crestal.push_back({ m,v });
	}
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		back.push_back(c);
	}

	sort(crestal.begin(), crestal.end());
	sort(back.begin(), back.end());

	int count{};
	for (int i = 0; i < k; i++)
	{
		while (n > count && back[i] >= crestal[count].first)
		{
			pq.push(crestal[count].second);
			count++;
		}

		if(pq.empty() == false)
		{
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << endl;
}