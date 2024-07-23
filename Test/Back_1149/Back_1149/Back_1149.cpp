#include <iostream>

using namespace std;

int n;
int RGB[1001][3];
int DP[1001][3];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];

	DP[0][0] = RGB[0][0];
	DP[0][1] = RGB[0][1];
	DP[0][2] = RGB[0][2];

	for (int i = 1; i < n; i++)
	{
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + RGB[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + RGB[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + RGB[i][2];
	}

	int result = min( DP[n - 1][0],DP[n - 1][1]);
	result = min(result, DP[n - 1][2]);
	cout << result << endl;
}