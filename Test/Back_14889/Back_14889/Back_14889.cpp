#include <iostream>
#include <cmath>

using namespace std;

int n;
int board[21][21];
bool check[22];
int result = 1000001;

void DFS(int index, int pos)
{
	if(index == n/2)
	{
		int start{}, end{};

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (check[i] == true && check[j] == true)
					start += board[i][j];
				if (check[i] == false && check[j] == false)
					end += board[i][j];
			}
		}

		int temp = abs(start - end);

		if (result > temp)
			result = temp;

		return;
	}

	for (int i = pos; i <= n; i++)
	{
		check[i] = true;
		DFS(index + 1, i + 1);
		check[i] = false;

		if(check[1] == false)
			return;
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}

	DFS(0, 1);

	cout << result;
}
