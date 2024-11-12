#include <iostream>
#include <queue>

using namespace std;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int r, c, ret;
char map[21][21];
char visited[27];

void Go(int x, int y, int cnt)
{
	ret = max(ret, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<0||nx>=r||ny<0||ny>=c)
			continue;
		int next = map[nx][ny] - 'A';

		if(visited[next] == 0)
		{
			visited[next] = 1;
			Go(nx, ny, cnt + 1);
			visited[next] = 0;
		}
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	visited[map[0][0] - 'A'] = 1;
	Go(0, 0, 1);
	cout << ret << endl;
}