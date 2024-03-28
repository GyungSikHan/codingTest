#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int Find(vector<int>& un, int data)
{
    if(un[data] == data)
        return data;
    return un[data] = Find(un, un[data]);
}

void Union(vector<int>& un, int first, int second)
{
    first = Find(un,first);
    second = Find(un, second);

    if(first != second)
        un[first] = second;
    else
        un[second] = first;
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

    int sum{};

    for (int i = 0; i < e; i++)
    {
        if(Find(un, edgeList[i].second.first) != Find(un, edgeList[i].second.second))
        {
            Union(un, edgeList[i].second.first, edgeList[i].second.second);
            sum += edgeList[i].first;
        }
    }

    cout<<sum<<endl;
}