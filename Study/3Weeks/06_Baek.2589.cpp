#include <iostream>
#include <queue>
using namespace std;

int dX[4] = {-1,0,1,0};
int dY[4] = {0,1,0,-1};

int n,m;
char Map[50][50];
int Visited[50][50];
int Result = 0;

queue<pair<int, int>> q;

void BFS(int x, int y)
{
    memset(Visited, 0, sizeof(Visited));
    q.push({x,y});
    Visited[x][y] = 1;

    while (q.empty() == false)
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int X = dX[i] + currX;
            int Y = dY[i] + currY;
            if(X < 0 || X >= n || Y < 0 || Y >= m || Visited[X][Y] != 0 || Map[X][Y] == 'W')
                continue;
            Visited[X][Y] = Visited[currX][currY] + 1;
            q.push({X,Y});
            Result = max(Result, Visited[X][Y]);
        }
    }
    
}

int main()
{
    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>Map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(Map[i][j] == 'L')
                BFS(i, j);
        }
    }
    
    cout<<Result - 1<<endl;
    
}