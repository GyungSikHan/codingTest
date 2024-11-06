#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const long long MAX = 200001 * 2;
int n, k;
long long Count[MAX];
long long Time[MAX];
queue<long long> q;

int main()
{
	cin >> n >> k;
	if(n == k)
	{
		cout << 0 << endl;
		cout << 1 << endl;
		return 0;
	}

	Count[n] = 1;
	Time[n] = 1;
	q.push(n);

	while (q.empty() == false)
	{
		int now = q.front();
		q.pop();

		for (int next : {now -1, now+1, now*2})
		{
			if(next < 0 || next > MAX)
				continue;

			if (Time[next] == 0)
			{
				Time[next] = Time[now] + 1;
				Count[next] += Count[now];
				q.push(next);
			}
			else if(Time[next] == Time[now] + 1)
 				Count[next] += Count[now];
		}
	}

	cout << Time[k] - 1 << endl;
	cout << Count[k] << endl;
}