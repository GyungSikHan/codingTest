#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int INF = 1e9;
int a, b, c;

int main()
{
    int n{},m{};
    cin>>n;
    cin>>m;

    vector<vector<int>> rod(n+1,vector<int>(n+1, INF));

    for (int i = 1; i <= n; i++)
        rod[i][i] = 0;
    
    for (int i = 0; i < m; i++)
    {
        cin >>a >> b >> c;
        rod[a][b] = min(rod[a][b], c);
    }

    for(int k = 1; k <= n; k++)
    {
        for (int s = 1; s <= n; s++)        
        {
            for (int e = 1; e <= n; e++)
            {
                rod[s][e] = min(rod[s][e], rod[s][k] + rod[k][e]);
            }
        }       
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(rod[i][j] == INF)
                cout<<0<<" ";
            else
                cout<<rod[i][j]<<" ";
        }
        cout<<endl;
    }
}