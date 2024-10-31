#include <iostream>
#include <queue>
using namespace std;

double n;
//priority_queue<double,vector<double>,greater<double>> pq;
priority_queue<double> pq;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double a{};
		cin >> a;
		if(pq.size() == 5)
		{
			pq.push(a);
			pq.pop();
		}
		else
			pq.push(a);
	}
	cout << endl;

	vector<double> v;
	while (pq.empty() == false)
	{
		v.push_back(pq.top());
			pq.pop();
	}
	sort(v.begin(), v.end());
	for (double d : v)
		cout << d << endl;
}