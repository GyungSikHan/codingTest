﻿#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n{}, m{};
vector<vector<int>> Tree;
vector<bool> Visit;
vector<int> Parent;
vector<int> Depth;
int depth = 1;

//void DFS(int node)
//{
//	Visit[node] = true;
//	Depth[node] = depth;
//	for (auto iter : Tree[node])
//	{
//		if (Visit[iter] == false)
//		{
//			depth++;
//			Parent[iter] = node;
//			DFS(iter);
//			depth--;
//		}
//	}
//}

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	Visit[node] = true;
	Depth[node] = depth;

	while (q.empty() == false)
	{
		int currNode = q.front();
		q.pop();
		Visit[currNode] = true;

		for (auto a : Tree[currNode])
		{
			if(Visit[a] == false)
			{
				Depth[a] = Depth[currNode] + 1;
				Parent[a] = currNode;
				q.push(a);
			}
		}
	}
}

int LCA(int a, int b)
{
	while (a != b)
	{
		if(Depth[a] > Depth[b])
		{
			a = Parent[a];
		}
		else if(Depth[a] < Depth[b])
		{
			b = Parent[b];
		}
		else if(Depth[a] == Depth[b])
		{
			a = Parent[a];
			b = Parent[b];
		}
	}

	return a;
}

int main()
{
	int a{}, b{};
	cin >> n;

	Tree.resize(n + 1);
	Visit.resize(n + 1, false);
	Parent.resize(n + 1, 0);
	Depth.resize(n + 1, 0);
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	//DFS(1);
	BFS(1);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << LCA(a, b) << endl;
	}

}