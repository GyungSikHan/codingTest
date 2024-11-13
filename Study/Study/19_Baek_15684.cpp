#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, h;
int a, b;
int arr[11][30];

int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		arr[b][a] = b + 1;
		arr[b+1][a] = b;
	}

	int x{};
}