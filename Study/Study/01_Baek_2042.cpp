#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> pantwick;

void Update(int index, long long value)
{
	while (index <= n)
	{
		pantwick[index] += value;
		index += index & -index;
	}
}

long long Query(int index)
{
	long long sum{};
	while (index > 0)
	{
		sum += pantwick[index];
		index -= index & -index;
	}
	return sum;
}

long long Range(int left, int right)
{
	return Query(right) - Query(left - 1);
}


int main()
{
	cin >> n >> m >> k;
	arr.resize(n + 1, 0);
	pantwick.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		Update(i, arr[i]);
	}

	m = m + k;
	while (m != 0)
	{
		int a{};
		cin >> a;
		if (a == 1)
		{
			int b{};
			long long c{};
			cin >> b >> c;
			long long temp = c - arr[b];
			arr[b] = c;
			Update(b, temp);

		}
		else
		{
			int b{}, c{};
			cin >> b >> c;
			cout << Range(b, c) << endl;
		}
		m--;
	}
}
