#include<iostream>
#include<vector>
#include <queue>

using namespace std;

long long MAX = 500000;
int n, k;
vector<long long> Time;
queue<long long> q;

int main()
{
	cin >> n >> k;
	if(n == k)
	{
		cout << 0 << endl;
		return 0;
	}

	Time.resize(MAX, 0);

	Time[n] = 1;
	q.push(n);
	int index = 1;

	while (q.empty() == false)
	{
		long long curr = q.front();
		long long temp = k + Time[curr] - 1;
		q.pop();
		if(temp == curr)
			break;
		for (long long next : {curr + 1, curr - 1, curr * 2})
		{
			if(next < 0 || next > MAX)
				continue;

			if (next > 500000)
			{
				Time[k] = -1;
				break;
			}
			else if(Time[next] == 0)
			{
				Time[next] = Time[curr] + 1;
				q.push(next);
			}
		}
	}

	if (Time[k] == -1)
		cout << -1 << endl;
	else
		cout << Time[k] - 1 << endl;

}