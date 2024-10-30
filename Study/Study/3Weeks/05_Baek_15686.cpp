#include <iostream>
#include <vector>
using namespace std;

int N,M;
int Map[51][51];
int Result = INT_MAX;
vector<vector<int>> ChickenList;
vector<pair<int, int>> Home;
vector<pair<int, int>> Cheicken;

void Combi(int start, vector<int> v)
{
    if(v.size() == M)
    {
        ChickenList.push_back(v);
        return;
    }

    for (int i = start + 1; i < Cheicken.size(); i++)
    {
        v.push_back(i);
        Combi(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin>>Map[i][j];
            if(Map[i][j] == 1)
                Home.push_back({i,j});
            if(Map[i][j] == 2)
                Cheicken.push_back({i,j});
        }
    }
    
    vector<int> v;
    Combi(-1, v);
    for (vector<int> iter : ChickenList)
    {
        int ret{};
        for (pair<int,int> home : Home)
        {
            int mini = INT_MAX;
            for (int cheicken : iter)
            {
                int dest = abs(home.first - Cheicken[cheicken].first) + abs(home.second - Cheicken[cheicken].second);
                mini = min(mini, dest);
            }
            ret += mini;
        }
        Result = min(Result, ret);
    }
    
    cout<<Result<<endl;
}