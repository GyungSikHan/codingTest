#include <iostream>

using namespace std;

int n;

int num;
long long k[101]{};

int main()
{
	cin >> n;

	k[1] = 1;
	k[2] = 1;
	k[3] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		for (int j = 4; j <= num; j++)
		{
			if (k[j] == 0)
				k[j] = k[j - 3] + k[j - 2];
		}
		cout << k[num] << endl;
	}

}
