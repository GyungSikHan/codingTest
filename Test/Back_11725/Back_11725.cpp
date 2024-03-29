﻿#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n{};
int a{}, b{};
vector<vector<int>> Tree;
vector<int> Parent;

void Bfs()
{
	queue<int> q;
	q.push(1);
	Parent[1] = 0;

	while (q.empty() == false)
	{
		int curr = q.front();
		q.pop();

		for (int i : Tree[curr])
		{
			if(Parent[i] == -1)
			{
				Parent[i] = curr;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	Tree.resize(n + 1);
	Parent.resize(n + 1, -1);

	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	Bfs();

	for (int i = 2; i <= n; i++)
	{
		cout << Parent[i] <<"\n";
	}
}