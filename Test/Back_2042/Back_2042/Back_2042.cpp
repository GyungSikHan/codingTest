#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long> Tree;

void ChangeVal(int index, long val)
{
	long temp = val - Tree[index];

	while (index > 0)
	{
		Tree[index] = Tree[index] + temp;
		index /= 2;
	}
}

void SetTree(int data)
{
	while (data != 1)
	{
		Tree[data / 2] += Tree[data];
		data--;
	}
}

long GetSum(int data1, long data2)
{
	long sum{};

	while (data1 <= data2)
	{
		if (data1 % 2 == 1)
			sum += Tree[data1];
		if (data2 % 2 == 0)
			sum += Tree[data2];

		data1 = (data1 + 1) / 2;
		data2 = (data2 - 1) / 2;
	}

	return sum;
}

int main()
{
	int n{}, m{}, k{};
	cin >> n >> m >> k;

	int treeHeight{};
	int length = n;

	while (length != 0)
	{
		length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int leftNodeStartIndex = treeSize / 2;

	Tree.resize(treeSize + 1);
	for (int i = leftNodeStartIndex; i < leftNodeStartIndex + n; i++)
	{
		cin >> Tree[i];
	}

	SetTree(treeSize - 1);

	for (int i = 0; i < m + k; i++)
	{
		int a{}, b{};
		long c{};

		cin >> a >> b >> c;

		if(a == 1)
		{
			ChangeVal(leftNodeStartIndex - 1 + b, c);
		}
		else if(a == 2)
		{
			b = b + leftNodeStartIndex - 1;
			c = c + leftNodeStartIndex - 1;
			cout << GetSum(b,c) << endl;
		}
	}
}