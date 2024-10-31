#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
vector<pair<int, int >> V;
vector<int> C;
int result;

int main()
{
	cin >> n >> k;
	V.resize(n, { 0,0 });
	C.resize(k, 0);
	for (int i = 0; i < n; i++)
		cin >> V[i].first >> V[i].second;
	for (int i = 0; i < k; i++)
		cin >> C[i];

	sort(C.begin(), C.end());
	sort(V.begin(), V.end());

	priority_queue<int> pq;
	int j{};
	for (int i = 0; i < k; i++)
	{
		while (j < n && V[j].first <= C[i])
		{
			pq.push(V[j].second);
			j++;
		}
		if(pq.size() != 0)
		{
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << endl;
}