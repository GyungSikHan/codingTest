#include <iostream>
#include <vector>

using namespace std;

int n;
int k = 1;
int MaxData;

void DN(vector<vector<int>>arr)
{
	MaxData = arr[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
				arr[i][j] = arr[i][j] + arr[i - 1][j];
			else if (j == i)
				arr[i][j] = arr[i][j] + arr[i - 1][j - 1];
			else
			{
				arr[i][j] = max(arr[i][j] + arr[i - 1][j - 1], arr[i][j] + arr[i - 1][j]);
			}

			MaxData = max(MaxData, arr[i][j]);
		}
	}
	int a{};
}

int main()
{
	cin >> n;
	vector<vector<int>>arr(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int data{};
			cin >> data;

			arr[i][j] = data;
		}
	}

	DN(arr);
	cout << MaxData << endl;
}
