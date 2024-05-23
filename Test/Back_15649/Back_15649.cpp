#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool visit[9];

void DFS(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if(visit[i] == false)
		{
			visit[i] = true;
			arr[cnt] = i;
			DFS(cnt + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	DFS(0);
}