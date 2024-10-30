#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n,m;
int Arr[8][8];
int Temp[8][8];
vector<pair<int, int>> V;

int Result;

void DFS(int x, int y)
{
    Temp[x][y] = 2;
    if(x-1>=0 && Arr[x-1][y] == 0 && Temp[x-1][y] == 0)
        DFS(x-1,y);
    if(x+1<n && Arr[x+1][y] == 0 && Temp[x+1][y] == 0)
        DFS(x+1,y);
    if(y-1>=0 && Arr[x][y-1] == 0 && Temp[x][y-1] == 0)
        DFS(x,y-1);
    if(y+1<n && Arr[x][y+1] == 0 && Temp[x][y+1] == 0)
        DFS(x,y+1);
}

void Wall(int data)
{
    if(data == 3)
    {
        memset(Temp, 0, sizeof(Temp));
        for (int i = 0; i < V.size(); i++)
        {
            DFS(V[i].first, V[i].second);    
        }
        data = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(Arr[i][j] == 0 && Temp[i][j] == 0)
                    data++;
            }
        }
        Result = max(Result, data);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(Arr[i][j] == 0)
                {
                    Arr[i][j] = 1;
                    Wall(data + 1);
                    Arr[i][j] = 0;
                }
            }
            
        }
        
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Arr[i][j];
            if(Arr[i][j] == 2)
                V.push_back(make_pair(i,j));
        }
    }
    Wall(0);
    cout<<Result<<endl;
}