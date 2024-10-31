#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> visited;
vector<int> prevList;
vector<int> v2;
int index{};
int ret;

void Go(int idx)
{
	if(idx == -1)
		return;
	v2.push_back(v[idx]);
	Go(prevList[idx]);
	return;
}

int main()
{
	cin >> n;
	v.resize(n, 0);
	visited.resize(n, 0);
	prevList.resize(n, -1);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i] && visited[i] < visited[j] + 1)
			{
				visited[i] = visited[j] + 1;
				prevList[i] = j;
				if(ret < visited[i])
				{
					ret = visited[i];
					index = i;
				}
			}
		}
	}

	Go(index);

	cout << ret+1 << endl;
	for (int i = v2.size() - 1; i >= 0; i--)
		cout << v2[i] << " ";
}