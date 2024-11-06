#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int MAX = 200002;
int n, k;
vector<int> Time, Node, Result;
queue<int> q;

void InpudData()
{
	int a = k;
	while (a > -1 )
	{
		Result.push_back(a);
		a = Node[a];
	}
}

int main()
{
	cin >> n >> k;
	Time.resize(MAX+1, 0);
	Node.resize(MAX+1, -1);

	q.push(n);
	Time[n] = 1;

	while (q.empty() == false)
	{
		int curr = q.front();
		q.pop();
		
		for (int next : {curr + 1, curr - 1, curr * 2})
		{
			if(next < 0 || next > MAX)
				continue;

			if(Time[next] == 0)
			{
				Time[next] = Time[curr] + 1;
				Node[next] = curr;
				q.push(next);
			}
		}
	}
	InpudData();
	

	cout << Time[k] - 1 << endl;
	for (int i = Result.size()-1; i >= 0; i--)
		cout << Result[i] << " ";
	cout << endl;

}