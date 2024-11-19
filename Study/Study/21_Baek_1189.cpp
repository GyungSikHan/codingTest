#include<iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int r, c, k;
char map[5][5];
bool visited[5][5];
int hx, hy;
int ret;

void DFS(int x,int y, int count)
{
	if(count == k)
	{
		if (hx == x && hy == y)
			ret++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] == true)
			continue;
		visited[nx][ny] = true;
		DFS(nx, ny, count + 1);
		visited[nx][ny] = false;
	}
}

int main()
{
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'T')
				visited[i][j] = true;
		}
	}
	hx = 0;
	hy = c - 1;
	visited[r-1][0] = true;
	DFS(r - 1, 0,1);

	cout << ret << endl;
}