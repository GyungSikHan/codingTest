#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int root;
vector<int> V;

int DFS(vector<vector<int>>& node, int data)
{
    int ret{};
    int child{};
    for (auto a : node[data])
    {
        if(a != m)
        {
            ret += DFS(node, a);
            child++;
        }
    }
    if(child == 0)
        return 1;
    return ret;
}

int main()
{
    cin >> n;
    vector<vector<int>> node(n);

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if(m != -1)
            node[m].push_back(i);
        else
            root = i;
    }
    cin >> m;
    if(m == root)
    {
        cout<< 0 << endl;
        return 0;
    }
    
    cout<<DFS(node, root) << endl;
}