#include <iostream>

using namespace std;

int n, total=0;
int col[15];

bool Check(int level)
{
	for (int i = 0; i < level; i++)
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;
	
	return true;
}


void NQueen(int x)
{
	if (x == n)
		total++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			col[x] = i;
			if (Check(x) == true)
				NQueen(x + 1);
		}
	}
}

int main()
{
	cin >> n;

	NQueen(0);
	cout << total << endl;
}