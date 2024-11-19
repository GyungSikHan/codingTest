#include <iostream>
#include <vector>

using namespace std;
const int INF = 987654321;
int n, m, h, a, b;
int bridge[31][11];
int result = INF;

bool Check()
{
	for (int i = 1; i <= n; i++)
	{
		int start=i;
		for (int j = 1; j <= h; j++)
		{
			if (bridge[j][start] == 1)
				start++;
			else if (bridge[j][start - 1] == 1)
				start--;
		}
		if(start != i)
			return false;
	}

	return true;
}

void Go(int here, int count)
{
	if(count > 3 || result <= count)
		return;
	if(Check() == true)
	{
		result = min(result, count);
		return;
	}

	for (int i = here; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if(bridge[i][j] == 1 || bridge[i][j-1] == 1 || bridge[i][j+1] == 1)
				continue;
			bridge[i][j] = 1;
			Go(i, count + 1);
			bridge[i][j] = 0;
		}
	}
}

int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		bridge[a][b] = 1;
	}
	Go(1, 0);
	if (result == INF)
		cout << -1 << endl;
	else
		cout << result << endl;
}