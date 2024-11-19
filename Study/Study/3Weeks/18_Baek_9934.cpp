#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int k;
int length;
int arr[1100];
vector<vector<int>> v;
void Go(int start, int end, int level)
{
	if (start > end)
		return;
	if (start == end)
	{
		v[level].push_back(arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	v[level].push_back(arr[mid]);
	Go(start, mid - 1, level + 1);
	Go(mid + 1, end, level + 1);
}

int main()
{
	cin >> k;
	length = (int)(pow(2, k)) - 1;
	v.resize(length + 1);
	for (int i = 0; i < length; i++)
		cin >> arr[i];
	Go(0, length, 1);

	for (int i = 1; i <= k; i++)
	{
		for (auto a : v[i])
			cout << a << " ";
		cout << endl;
	}
}
