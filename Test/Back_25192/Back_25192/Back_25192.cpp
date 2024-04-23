#include <iostream>
#include <set>

using namespace std;

set<string> Set;

int main()
{
	int n{};
	string s{};
	int length{};
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if(s == "ENTER")
		{
			length += (int)Set.size();
			Set.clear();
			continue;
		}
		Set.insert(s);
	}
	length += (int)Set.size();
	cout << length << endl;
}