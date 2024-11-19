#include <iostream>
#include <cmath>

using namespace std;

int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
const int INF = 987654321;
int n, result = INF, visited[10][10], cost[10][10];

bool Check(int x, int y)
{
	if (visited[x][y] == 1)
		return false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] == 1)
			return false;
	}
	return true;
}

int MakeFlower(int x, int y)
{
	visited[x][y] = 1;
	int sum = cost[x][y];
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		visited[nx][ny] = 1;
		sum += cost[nx][ny];
	}

	return sum;
}

void Erase(int x, int y)
{
	visited[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		visited[nx][ny] = 0;
	}
}

void DFS(int seed, int hap)
{
	if(seed == 3)
	{
		result = min(result, hap);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(Check(i,j) == true)
			{
				DFS(seed + 1, hap+MakeFlower(i, j));
				Erase(i, j);
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}
	DFS(0, 0);

	cout << result << endl;
}