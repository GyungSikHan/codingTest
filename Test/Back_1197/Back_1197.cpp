#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a{},b{},c{};
    int v{}, e{};
    cin>>v>>e;

    vector<pair<int, pair<int, int>> edgeList;
    vector<int> un(v+1,0);

    for(int i = 1; i <= v; i++)
        un[i] = i;

    for(int i = 0; i < e; i++)
    {
        cin>> a >> b >> c;
        edgeList.push_back({c,{a,b}});
    }


}