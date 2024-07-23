#include <iostream>

using namespace std;

int n{};
long long arr[100001]{};
long long dp[100001]{};
long long Sum{};

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	Sum = dp[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		if (Sum < dp[i])
			Sum = dp[i];
	}

	cout << Sum << endl;
}