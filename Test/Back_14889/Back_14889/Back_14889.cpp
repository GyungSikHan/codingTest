#include <iostream>
#include <cmath>

using namespace std;

int n;
int board[21][21];
bool check[22];
int result = 1000001;

void DFS(int curr, int next)
{
	if(curr == n/2)
	{
		int start{}, link{};

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (check[i] == true && check[j] == true)
					start += board[i][j];
				if (check[i] == false && check[j] == false)
					link += board[i][j];
			}
		}

		int temp = abs(start - link);

		if (result > temp)
			result = temp;

		return;
	}

	for (int i = next; i <= n; i++)
	{
		check[i] = true;
		DFS(curr + 1, i + 1);
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
