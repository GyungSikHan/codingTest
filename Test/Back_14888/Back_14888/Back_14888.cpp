#include <iostream>

using namespace std;

int n;
int d[11];
int datas[4];
int minData = 1000000001;
int maxData = -1000000001;

void DFS(int result, int index)
{
	if(n == index)
	{
		if (result > maxData)
			maxData = result;
		if (result < minData)
			minData = result;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if(datas[i] > 0)
		{
			datas[i]--;

			if (i == 0)
				DFS(result + d[index], index+1);
			else if (i == 1)
				DFS(result - d[index], index+1);
			else if (i == 2)
				DFS(result * d[index], index + 1);
			else
				DFS(result / d[index], index + 1);

			datas[i]++;
		}
	}

	return;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> d[i];

	for (int i = 0; i < 4; i++)
		cin >> datas[i];

	DFS(d[0], 1);

	cout << maxData << endl;
	cout << minData << endl;
}