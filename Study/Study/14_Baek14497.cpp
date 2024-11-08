#include<iostream>
#include <vector>
#include <queue>

using namespace std;
int dX[4] = { -1,0,1,0 }, dY[4] = { 0,1,0,-1 };
int n, m;
int myX, myY, taX, taY;
vector<vector<int>> map;
vector<vector<int>> visited;
int Count;

int main()
{
	cin >> n >> m;
	cin >> myX >> myY >> taX >> taY;
	map.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<int>(m, 0));
	
	map[myX][myY] = '*';
	map[taX][taY] = '#';

	for (int i = 0; i < n; i++)
	{
		for (int  j = 0; j < m; j++)
		{
			char c{};
			cin >> c;
			if ((i == myX && j == myY) || (i == taX && j == taY))
				continue;
			map[i][j] = c - 48;
		}
	}
	queue<pair<int, int>> q;
	q.push({ myX,myY });
	while (true)
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int currX = q.front().first;
			int currY = q.front().second;
			if(currX == taX && currY == taY)
				break;
			q.pop();
			//q.push 가 안됨
			//왜 안되는지 생각해보기
			for (int i = 0; i < 4; i++)
			{
				int x = currX + dX[i];
				int y = currY + dY[i];

				if(x < 0 || x >= n || y < 0 || y >= m)
					continue;
				if(visited[x][y] != 0)
					continue;
				if (map[x][y] == 1)
				{
					map[x][y] = 0;
					visited[x][y] += 1;
				}
				else
					q.push({ x,y });
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		Count++;
	}

	cout << Count << endl;

}