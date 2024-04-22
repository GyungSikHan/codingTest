#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq;
int n;
int a;

int main(int argc, char* argv[])
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		dq.push_back(make_pair(a, i + 1));
	}

	while (dq.empty() == false)
	{
		int curr = dq.front().first;
		cout << dq.front().second<<" ";
		dq.pop_front();

		if (dq.empty() == true)
			break;

		if(curr > 0)
		{
			for (int i = 0; i < curr-1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for (int i = 0; i < curr*(-1); i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
}
