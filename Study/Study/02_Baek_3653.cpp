#include <iostream>
#include <vector>

using namespace std;

int t, n, m;
vector<int> position;
vector<int> fenweick;
int currerntTop;

void Update(int index, int value, int size)
{
	while (index < size)
	{
		fenweick[index] += value;
		index += index & -index;
	}
}

int sum(int index)
{
	int sum{};
	while (index > 0)
	{
		sum += fenweick[index];
		index -= index & -index;
	}
	return sum;
}

int RangeSum(int left, int right)
{
	return sum(right) - sum(left - 1);
}

int MoveTop(int move, int totalmove)
{
	int sum = RangeSum(1, position[move] - 1);

	Update(position[move], -1, totalmove);

	position[move] = currerntTop--;
	Update(position[move], 1, totalmove);

	return sum;
}

void MoveQuery(vector<int>& query, int totalmove)
{
	for (int a : query)
	{
		int moveQuery = MoveTop(a, totalmove);
		cout << moveQuery << " ";
	}
	cout << endl;
}

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int length = n + m;
		position.assign(n + 1, 0);
		fenweick.assign(length + 1, 0);
		currerntTop = m;

		for (int i = 1; i <= n; i++)
		{
			position[i] = m + i;
			Update(position[i], 1, length);
		}

		vector<int> query(m,0);
		for (int i = 0; i < m; i++)
			cin >> query[i];

		MoveQuery(query, length);
	}
}