#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dY[4] = {-1,0,1,0};
int dX[4] = {0,1,0,-1};

int Count;

void DFS(vector<vector<int>> maps, vector<vector<bool>>& Visited, int y, int x)
{
    Visited[y][x] = true;

    for (int i = 0; i < 4; i++) 
    {
        int nY = y+dY[i];
        int nX = x+dX[i];
        if(nY >= 0 && nY < n && nX >= 0 && nX < n)
            if(maps[nY][nX] == 1 && Visited[nY][nX] == false)
                DFS(maps, Visited, nY, nX);
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> maps(n,vector<int>(m, 0));
    vector<vector<bool>> Visited(n, vector<bool>(m,false));
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin>>maps[i][j];
    
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if(maps[i][j] == 1 && Visited[i][j] == false)
            {
                DFS(maps, Visited, i, j);
                Count++;
            }
        }
    }

    cout<<Count<<endl;
}