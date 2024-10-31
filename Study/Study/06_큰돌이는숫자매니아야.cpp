#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<int> v;
vector<bool> visited;
int ret;
int main()
{
	cin >> n;
	v.resize(n, 0);
	visited.resize(n, false);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> k;
	sort(v.begin(), v.end());

	int l{}, r = v.size() - 1;
	while (l < r)
	{
		if (v[l] + v[r] == k)
		{
			r--;
			ret++;
		}
		else if (v[l] + v[r] > k)
			r--;
		else if (v[l] + v[r] < k)
			l++;
	}

	cout << ret << endl;
}