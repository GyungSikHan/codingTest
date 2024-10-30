#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int >num;
vector<char> op;
int result = -987654321;

int Oper(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	return a * b;
}

void Solve(int here, int _num)
{
	if(here == num.size() - 1)
	{
		result = max(result, _num);
		return;
	}

	Solve(here + 1, Oper(_num, num[here + 1], op[here]));
	if(here+2 <= num.size()-1)
	{
		int temp = Oper(num[here + 1], num[here + 2], op[here + 1]);
		Solve(here + 2, Oper(_num, temp, op[here]));
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c{};
		cin >> c;
		if (c == '+' || c == '-' || c == '*')
			op.push_back(c);
		else
			num.push_back(c - 48);
	}

	Solve(0, num[0]);
	cout << result << endl;
}