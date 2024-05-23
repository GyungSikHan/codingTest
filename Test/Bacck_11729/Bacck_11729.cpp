#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int n, int start, int end, int aux)
{
	if(n == 1)
	{
		cout << start << " " << end << "\n";
		return;
	}

	Hanoi(n - 1, start, aux, end);
	cout << start << " " << end << "\n";
	Hanoi(n - 1, aux, end, start);
}

int main()
{
	int n{};
	cin >> n;

	std::cout << (1 << n) - 1 << '\n';
	//cout << pow(2, n) - 1 << endl; // 시간초과남

	Hanoi(n, 1, 3, 2);
	
}
