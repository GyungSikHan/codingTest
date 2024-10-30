#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000;
int n, k;
int result = 987654321;
int visited[MAX+4];
long long cnt[MAX+4];

int main()
{
	cin >> n >> k;

	if(n == k)
	{
		cout << 0 << "\n" << 1 << endl;
		return 0;
	}

	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);

	while (q.empty() == false)
	{
		int now = q.front();
		q.pop();

		for (int next : {now+1, now-1,now*2})
		{
			if(next >= 0 && next <= MAX)
			{
				if (visited[next] == 0)
				{
					q.push(next);
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now];
				}
				else if (visited[next] == visited[now] + 1)
					cnt[next] += cnt[now];
			}
		}
	}

	cout << visited[k] - 1 << "\n" << cnt[k] << endl;
}