#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dX[4] = { -1,0,1,0 }, dY[4] = { 0,1,0,-1 };

int n, m, x, y, x2, y2;
char map[301][301];
int visited[301][301];

int main()
{
	cin >> n >> m;
	cin >> x >> y >> x2 >> y2;
	x--;
	y--;
	x2--;
	y2--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;

	int cnt{};
	while (map[x2][y2] != '0')
	{
		cnt++;
		queue<pair<int, int>>temp;
		while (q.empty() == false)
		{
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextX = nx + dX[i];
				int nextY = ny + dY[i];

				if(nextX < 0 || nextX >= n || nextY < 0|| nextY >= m || visited[nextX][nextY] != 0)
					continue;
				visited[nextX][nextY] = cnt;
				if (map[nextX][nextY] != '0')
				{
					map[nextX][nextY] = '0';
					temp.push({ nextX,nextY });
				}
				else
					q.push({ nextX,nextY });
			}
		}
		q = temp;
	}

	cout << visited[x2][y2] << endl;
}