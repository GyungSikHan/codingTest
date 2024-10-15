#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;  

int n, c;
vector<pair<int, int>> v; 
map<int, int> mp, mp_first; 
bool cmp(pair<int,int> a, pair<int, int> b)
{
	if(a.first == b.first)
		return mp_first[a.second] < mp_first[b.second];
	
	return a.first > b.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c; 
	for(int i = 0; i < n; i++)
    {
        int z{};
		cin >> z;
        mp[z]++;
		if(mp_first[z] == 0) 
            mp_first[z] = i + 1; 
	} 
	for(auto it : mp)
		v.push_back({it.second, it.first});
	
	sort(v.begin(), v.end(), cmp);
	for(auto i : v)
		for(int j = 0; j < i.first; j++)
			cout << i.second << " ";
		
	return 0;
}