#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct SCV
{
	int f, s, t;
};

int damage[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,9,3},
	{1,3,9}
};

int HP[61][61][61];
int n;
queue<SCV> scv;
int temp[3]{};

int Solve(int f, int s, int t)
{
	HP[f][s][t] = 1;

	while (scv.empty() == false)
	{
		int F = scv.front().f;
		int S = scv.front().s;
		int T = scv.front().t;
		scv.pop();

		if(HP[0][0][0] != 0)
			break;

		for (int i = 0; i < 6; i++)
		{
			int damageF = max(0, F - damage[i][0]);
			int damageS = max(0, S - damage[i][1]);
			int damageT = max(0, T - damage[i][2]);

			if(HP[damageF][damageS][damageT] != 0)
				continue;

			HP[damageF][damageS][damageT] = HP[F][S][T] + 1;
			scv.push({ damageF,damageS,damageT });
		}
	}

	return HP[0][0][0] - 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> temp[i];
	scv.push({ temp[0], temp[1], temp[2] });
	cout<<Solve(temp[0], temp[1], temp[2])<<endl;
}