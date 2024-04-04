#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int m;
vector<vector<int >> Tree;
vector<bool> Visit;
vector<int> Depth;
vector<vector<int>> Parent;

void Print()
{
	for (int i = 1; i <= n; i++)
	{
		cout << Depth[i] << " ";
	}
}

int BFS(int data)
{
	int maxDepth{};
	int depth = 1;
	queue<int> q{};
	q.push(data);
	Visit[data] = true;
	Depth[data] = depth;
	
	while (q.empty() == false)
	{
		int curr = q.front();
		q.pop();

		for (auto iter : Tree[curr])
		{
			if(Visit[iter] == false)
			{
				Depth[iter] = Depth[curr] + depth;
				maxDepth = max(maxDepth, Depth[iter]);
				Visit[iter] = true;
				q.push(iter);
			}
		}
	}

	return maxDepth;
}

int main()
{
	int a{}, b{};
	cin >> n;

	Tree.resize(n + 1);
	Visit.resize(n + 1, false);
	Depth.resize(n + 1,0);

	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	int temp = BFS(1);

}
