#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> num;
vector<char> oper;
char c;
int length;
int ret = -987654321;

int Oper(int data, int data2, char op)
{
	if (op == '+')
		return data + data2;
	else if (op == '-')
		return data - data2;
	return data * data2;
}

void Solve(int data, int number)
{
	if(length == number)
	{
		ret = max(ret, data);
		return;
	}

	Solve(Oper(data, num[number + 1], oper[number]), number + 1);
	if(number+2 <= length)
	{
		int temp = Oper(num[number + 1], num[number + 2], oper[number + 1]);
		Solve(Oper(data, temp, oper[number]), number + 2);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == '+' || c == '*' || c == '-')
			oper.push_back(c);
		else
			num.push_back(c - 48);
	}
	length = num.size()-1;

	Solve(num[0], 0);
	cout << ret << endl;
}