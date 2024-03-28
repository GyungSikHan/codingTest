#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool Find(vector<int> un, int fi, int se)
{
    int temp = un[fi];

    if(un[temp] == un[se])
        return false;

    return true;
}

int main()
{
    int a{},b{},c{};
    int v{}, e{};
    cin>>v>>e;

    vector<pair<int, pair<int, int>>> edgeList;
    vector<int> un(v+1,0);

    for(int i = 1; i <= v; i++)
        un[i] = i;

    for(int i = 0; i < e; i++)
    {
        cin>> a >> b >> c;
        edgeList.push_back({c,{a,b}});
    }

    sort(edgeList.begin(),edgeList.end());

    for (int i = 0; i < e; i++)
    {
        if(Find(un, edgeList[i].second.first, edgeList[i].second.second) == true)
        {
            un[edgeList[i].second.first] = edgeList[i].second.second;
        }
    }



    int n{};

}