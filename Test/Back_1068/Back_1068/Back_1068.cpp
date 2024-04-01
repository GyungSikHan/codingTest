#include <iostream>
#include <vector>

using namespace std;

int n{}, a{};
int root{};
vector<vector<int>> v(51);
int leaf{};

int DFS(int data)
{
	if (a == data)
		return -1;
	if (v[data].size() == 0)
		return leaf++;

	for (auto iter : v[data])
	{
		int temp = DFS(iter);
		if (temp == -1 && v[data].size() == 1)
			leaf++;
	}

	return leaf;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (a == -1)
			root = i;
		else
			v[a].push_back(i);
	}

	cin >> a;

	DFS(root);
	cout << leaf;
	
}
