#include <iostream>
#include <vector>

using namespace std;

vector<int> Adj[10];
bool Visit[10];

void Solve(int data)
{
    cout<<data<<endl;
    Visit[data] = true;

    for (auto index : Adj[data]) 
    {
        if(Visit[index] == false)
            Solve(index);
    }
}

int main()
{
    Adj[1].push_back(2);
    Adj[1].push_back(3);
    Adj[2].push_back(1);
    Adj[3].push_back(1);
    Adj[3].push_back(4);

    for (int i = 0; i < 10; i++) 
    {
        if(Adj[i].size() != 0 && Visit[i] == false)
            Solve(i);
    }
}