#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;

int T, n, m;
vector<int> v;
int a;

string Check(int temp)
{
	int l{}, r = v.size() - 1;
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (v[mid] > temp)
			r = mid - 1;
		else if (v[mid] == temp)
			return "ū���̴� �����!";
		else
			l = mid + 1;
	}
	return "ū���̴� ��Ծ���!";
}

int main()
{
	cin >> T;

	while (T != 0)
	{
		cin >> n;
		v.resize(n, 0);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		sort(v.begin(), v.end());
		cin >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> a;
			cout << Check(a) << endl;
		}
		T--;
	}
}