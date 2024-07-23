#include <iostream>
#include <vector>
using namespace std;

int arr[9][9], L;
vector<pair<int, int> > v;

bool isend = false;

bool check(int y, int x, int value)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[y][j] == value)
				return false;
			if (arr[i][x] == value)
				return false;
		}
	}

	int partY = y / 3 * 3, partX = x / 3 * 3;

	for (int i = partY; i < partY + 3; i++)
	{
		for (int j = partX; j < partX + 3; j++)
		{
			if (arr[i][j] == value)
				return false;
		}
	}

	return true;
}

void DFS(int cur)
{
	if (isend == true)
		return;
	if (cur == L)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		isend = true;
	}
	else
	{
		int y = v[cur].first, x = v[cur].second;
		for (int i = 1; i <= 9; i++)
		{
			if (check(y, x, i) == true)
			{
				arr[y][x] = i;
				DFS(cur + 1);
				arr[y][x] = 0;
			}
		}
	}
}


int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				v.push_back({ i,j });
			}
		}
	}
	L = v.size();
	DFS(0);
}
