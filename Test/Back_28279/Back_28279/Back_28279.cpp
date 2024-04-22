﻿#include <iostream>
#include <deque>

using namespace std;

deque<int> q;
int n{};
int m{};
int a{};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	while(n--)
	{
		cin >> m;

		switch (m)
		{
		case 1:
			cin >> a;
			q.push_front(a);
			break;
		case 2:
			cin >> a;
			q.push_back(a);
			break;
		case 3:
			if (q.empty() == false)
			{
				cout << q.front() << "\n";
				q.pop_front();
				break;
			}
			cout << -1 << "\n";
			break;
		case 4:
			if (q.empty() == false)
			{
				cout << q.back() << "\n";
				q.pop_back();
				break;
			}
				cout << -1 << "\n";
			break;
		case 5:
			cout << q.size() << "\n";
			break;
		case 6:
			if (q.empty() == true)
			{
				cout << 1 << "\n";
				break;
			}
			cout << 0 << "\n";
			break;
		case 7:
			if (q.empty() == false)
			{
				cout << q.front() << "\n";
				break;
			}
			cout << -1 << "\n";
			break;
		case 8:
			if (q.empty() == false)
			{
				cout << q.back() << "\n";
				break;
			}
			cout << -1 << "\n";
			break;
		}
	}
}