#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int kmax;
int parent[21][100001];
vector<int> Depth;
vector<bool> Visit;
vector<vector<int>> Tree;

int main()
{
	int a{}, b{};
	cin >> n;

	Tree.resize(n + 1);
	Depth.resize(n + 1, 0);
	Visit.resize(n + 1, false);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	//n이 노드의 개수

}