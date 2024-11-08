#include<iostream>
#include<vector>
#include <queue>

using namespace std;

const int MAX = 500000;
int n, k;
int turn = 1;
int visited[2][MAX + 4];
bool mit;
queue<int> q;

int main()
{
	cin >> n >> k;

	if(n == k)
	{
		cout << 0 << endl;
		return 0;
	}

	q.push(n);
	visited[0][n] = 1;

	while (q.empty() == false)
	{
		k += turn;
		if(k > MAX)
			break;
		if(visited[turn%2][k] != 0)
		{
			mit = true;
			break;
		}
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int x = q.front();
			q.pop();
			for (int nX : {x+1,x-1,x*2})
			{
				if(nX<0||nX>MAX||visited[turn%2][nX] != 0)
					continue;
				visited[turn % 2][nX] = visited[(turn +  1) % 2][nX] + 1;
				if (nX == k)
				{
					mit = true;
					break;
				}

				q.push(nX);
			}
			if(mit == true)
				break;
		}
		if(mit == true)
			break;
		turn++;
	}
	 
	if (mit == true)
		cout << turn << endl;
	else
		cout << -1 << endl;

}