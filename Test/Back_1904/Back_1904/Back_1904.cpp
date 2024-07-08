#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n{};
	cin >> n;

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	else if(n == 2)
	{
		cout << 2 << endl;
		return 0;
	}

	vector<int> arr(n + 1, 0);
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;

	cout << arr[n] << endl;
	return 0;
}