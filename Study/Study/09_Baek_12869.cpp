#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int attack[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,9,3},
	{1,3,9}
};
int scv[3];
int visited[61][61][61];

struct A {
	int a, b, c;
};
queue<A>q;

int Solve(int a, int b, int c)
{
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	while (q.size())
	{
		int f = q.front().a;
		int s = q.front().b;
		int t = q.front().c;
		q.pop();

		if(visited[0][0][0] != 0)
			break;
		for (int i = 0; i < 6; i++)
		{
			int nF = max(0, f - attack[i][0]);
			int nS = max(0, s - attack[i][1]);
			int nT = max(0, t - attack[i][2]);
			if (visited[nF][nS][nT] != 0)
				continue;
			visited[nF][nS][nT] = visited[f][s][t] +1;
			q.push({ nF,nS,nT });
		}
	}

	return visited[0][0][0] - 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> scv[i];
	cout << Solve(scv[0],scv[1],scv[2]) << endl;
}