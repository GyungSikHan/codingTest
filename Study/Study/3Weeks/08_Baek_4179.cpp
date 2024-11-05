#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dX[4] = { -1,0,1,0 }, dY[4] = { 0,1,0,-1 };

int INF = 987654321;
int r, c, ret;
int jX, jY;
vector<vector<char>> map;
vector<vector<int>> fire;
vector<vector<int>> J;
queue<pair<int, int>> q;

bool Check(int x, int y)
{
	if (x >= 0 && x < r && y >= 0 && y < c)
		return true;
	return false;
}

int main()
{
	cin >> r >> c;
	map.resize(r, vector<char>(c));
	fire.resize(r, vector<int>(c, INF));
	J.resize(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 'F')
			{
				fire[i][j] = 1;
				q.push({ i,j });
			}
			else if(map[i][j] == 'J')
			{
				jX = i;
				jY = j;
			}
		}
	}

	while (q.empty() == false)
	{
		int currX = q.front().first;
		int currY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = currX + dX[i];
			int y = currY + dY[i];

			if (Check(x,y) == false)
				continue;
			if(fire[x][y] != INF || map[x][y] == '#')
				continue;

			fire[x][y] = fire[currX][currY] + 1;
			q.push({ x,y });
		}
	}

	J[jX][jY] = 1;
	q.push({ jX,jY });

	while (q.empty() == false)
	{
		int currX = q.front().first;
		int currY = q.front().second;
		q.pop();

		if(currX == 0 || currX == r-1 || currY == 0 || currY == c-1)
		{
			ret = J[currX][currY];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int x = currX + dX[i];
			int y = currY + dY[i];
			if (Check(x,y) == false)
				continue;
			if (J[x][y] != 0 || map[x][y] == '#')
				continue;
			if(fire[x][y] <= J[currX][currY] + 1)
				continue;

			J[x][y] = J[currX][currY] + 1;
			q.push({ x,y });
		}
	}

	if (ret == 0)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ret << endl;

}