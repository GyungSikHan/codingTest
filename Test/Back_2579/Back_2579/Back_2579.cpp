#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> Scores;
vector<int> DP;

int main()
{
	cin >> n;
	Scores.resize(n + 1, 0);
	DP.resize(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> Scores[i];

	DP[1] = Scores[1];
	DP[2] = Scores[1] + Scores[2];

	for (int i = 3; i <= n; i++)
	{
		DP[i] = max(DP[i - 3] + Scores[i - 1] + Scores[i], DP[i - 2] + Scores[i]);
	}

	cout << DP[n] << endl;
}