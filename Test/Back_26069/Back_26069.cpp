#include <iostream>
#include <map>

using namespace std;

map<string, bool> name;

int main()
{
	int n{};
	cin >> n;
	string s1{}, s2{};

	while (n--)
	{
		cin >> s1 >> s2;

		if (s1 == "chongchong")
			name.insert({ s1, true });
		else if (s2 == "chongchong")
			name.insert({ s2, true });

		if (name[s1] == true)
			name[s2] = true;
		if (name[s2] == true)
			name[s1] = true;
	}
	int count{};
	for (auto iter : name)
		if (iter.second == true)
			count++;

	cout << count << endl;
}