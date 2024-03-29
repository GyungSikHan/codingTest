#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int n{};
int a{}, b{};
vector<vector<int>> tree;
vector<int> parent;

void Serch(int root)
{
    queue<int> q;
    q.push(root);
    parent[root] = 0;

    while (q.empty() == false)
    {
        int currNode = q.front();
        q.pop();

        for(int i : tree[currNode])
        {
            if(parent[i] == -1)
            {
                parent[i] = currNode;
                q.push(i);
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    tree.resize(n+1);
    parent.resize(n+1, -1);
    
    for (int i = 0; i < n - 1; i++)
    {
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }


    Serch(1);
    for(int i = 2; i <= n; i++)
        cout<<parent[i]<<endl;
}