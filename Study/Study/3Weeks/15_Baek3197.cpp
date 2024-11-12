#include <iostream>
#include <queue>

using namespace std;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int r, c, day;
char map[1501][1501];
int visited[1501][1501];
int swanVisited[1501][1501];
int waterVisited[1501][1501];
queue<pair<int, int>> swan;
queue<pair<int, int>> swanTemp;
queue<pair<int, int>> water;
queue<pair<int, int>> waterTemp;
int sx, sy;

void Reset(queue<pair<int, int>>& a)
{
	queue<pair<int, int>>temp;
	swap(a, temp);
}

bool IsAllive()
{
	while (swan.empty() == false)
	{
		int x = swan.front().first;
		int y = swan.front().second;
		swanVisited[x][y] = 1;
		swan.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c || swanVisited[nx][ny] == 1)
				continue;
			swanVisited[nx][ny]= 1;
			if (map[nx][ny] == '.')
				swan.push({ nx,ny });
			else if(map[nx][ny] == 'X')
				swanTemp.push({ nx,ny });
			else if (map[nx][ny] == 'L')
				return true;
		}
	}

	return false;
}

void IceWater()
{
	while (water.empty() == false)
	{
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0|| nx>=r||ny<0||ny>=c||visited[nx][ny] == 1)
				continue;
			if(map[nx][ny] == 'X')
			{
				visited[nx][ny] = 1;
				waterTemp.push({ nx,ny });
				map[nx][ny] = '.';
			}
		}

	}
}


int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 'L')
			{
				sx = i;
				sy = j;
			}
			if(map[i][j] != 'X')
			{
				water.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	swan.push({ sx,sy });

	while (IsAllive() == false)
	{
		swan = swanTemp;
		IceWater();
		water = waterTemp;
		Reset(swanTemp);
		Reset(waterTemp);

		day++;
	}

	cout << day << endl;
}