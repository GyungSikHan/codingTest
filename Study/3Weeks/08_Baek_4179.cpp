#include <iostream>
#include <vector>
using namespace std;

int dX[4] = {-1,0,1,0}, dY[4] = {0,1,0,-1};
vector<vector<char>> Map;
vector<vector<bool>> Visited;
int n,m;
char c;
int Count;
bool b;

void DFS(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
    {
        b = true;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nX = x + dX[i];
        int nY = y +dY[i];
        if(Map[nX][nY] == 'F' || Map[nX][nY] == '#')
            continue;
        if(Visited[nX][nY] == false)
        {
            Visited[nX][nY] = true;
            Count++;
            DFS(nX, nY);
            Visited[nX][nY] = false;
            Count--;
        }
    }
    
}

int main()
{
    cin>>n>>m;
    Map.resize(n,vector<char>(m));
    Visited.resize(n,vector<bool>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>Map[i][j];
        
    DFS(0,0);
    if(b == false)
        cout<<"IMPOSSIBLE"<<"\n";
    else
        cout<<Count<<"\n";
}