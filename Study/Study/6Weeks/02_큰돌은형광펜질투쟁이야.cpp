#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> color;
int l, r, mid, ret = 987654321;

bool Search(int data)
{
	int temp{};
	for (int i = 0; i < m; i++)
	{
		temp += color[i] / data;
		if (color[i] % data != 0)
			temp++;
	}

	return temp <= n;
}

int main()
{
	cin >> n >> m;
	color.resize(m, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> color[i];
		r = max(r, color[i]);
	}

	while (l <= r)
	{
		mid = (l + r) / 2;
		if (Search(mid) == true)
		{
			ret = min(ret, mid);
			r = mid - 1;
		}
		else
			l = mid + 1;
	}

	cout << ret << endl;
}