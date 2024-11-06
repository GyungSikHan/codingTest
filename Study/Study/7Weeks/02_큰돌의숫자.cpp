#include <iostream>
#include <vector>

using namespace std;

int t,n;
int dp[10001];

int main()
{
	cin >> t;
	dp[0] = 1;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 10000; j++)
		{
			if (j - i >= 0)
			{
				dp[j] += dp[j - i];
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp[n] << endl;
	}
}