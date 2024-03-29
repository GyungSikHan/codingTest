#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int n{};
int a{}, b{};
vector<int> parent;

void Serch(vector<vector<int>> tree, int root)
{
    vector<bool> visit(n+1, false);
    vector<vector<int>> temp;
    temp = tree[root];
    visit[root] = true;

    while (temp.empty() == false)
    {
        int node = temp.back();
        temp.pop_back();

        for(int i : tree[root])
        {
            if(visit[i] == false)
            {
                visit[i] = true;
                parent[i] = node;
                temp.push_back(i);
            }
        }
        
    }
}

int main()
{
    cin>>n;

    vector<vector<int>> tree(n+1);
    parent.resize(n+1);
    for (int i = 0; i < n - 1; i++)
    {
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    

    Serch(tree, 1);
    

}