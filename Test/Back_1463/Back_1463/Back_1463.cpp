#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int x{};
	cin >> x;

	vector<int> v(x + 1, 0);
	
	for (int i = 2; i <= x; i++)
	{
		v[i] = v[i - 1] + 1;

		if (i % 2 == 0)
			v[i] = min(v[i], v[i / 2] + 1);
		if(i % 3 == 0)
			v[i] = min(v[i], v[i / 3] + 1);
	}

	cout << v[x] << endl;
}