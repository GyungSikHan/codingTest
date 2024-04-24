#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> datas;
int n;

int main()
{
	int temp{}, range{}, middle{}, mostv{}, mean{}, most = -9999;
	int number[8001]{};
	bool notFirst{};

	cin >> n;

	datas.resize(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		datas[i] = temp;
		mean += temp;
		number[temp + 4000]++;
	}

	sort(datas.begin(), datas.end());
	for (int i = 0; i < 8001; i++)
	{
		if (number[i] == 0)
			continue;
		if (number[i] == most)
		{
			if (notFirst == true)
			{
				mostv = i - 4000;
				notFirst = false;
			}
		}
		if (number[i] > most)
		{
			most = number[i];
			mostv = i - 4000;
			notFirst = true;
		}
	}

	mean = round((float)mean / n);
	middle = datas[datas.size() / 2];
	range = datas.back() - datas.front();

	cout << mean << endl;
	cout << middle << endl;
	cout << mostv << endl;
	cout << range << endl;
}