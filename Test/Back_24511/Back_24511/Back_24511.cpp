#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> de;
int n{};
int m{};
int a{};
bool flag[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> flag[i];
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		if (flag[i] == 0)
			de.push_back(m);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a;
		de.push_front(a);
		cout << de.back() << " ";
		de.pop_back();
	}
}