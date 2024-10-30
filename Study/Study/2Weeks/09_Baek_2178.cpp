#include <iostream>
#include<queue>
using namespace std;

int y[4] = {-1,0,1,0};
int x[4] = {0,1,0,-1};

int n,m;
int bard[104][104];

int visited[104][104];
queue<pair<int, int>> q;

void BFS(int nY, int nX)
{
    q.push({nY, nX});
    visited[nY][nX] = 1;

    while (q.empty() == false)
    {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int X = currX+x[i];
            int Y = currY+y[i];

            if(Y >= 1 && Y <= n && X >= 1 && X <= m)
            {
                if(bard[Y][X] == 1 && visited[Y][X] == 0)
                {
                    q.push({Y,X});
                    visited[Y][X] = visited[currY][currX] + 1;
                }
            }
        }   
    }
    
}

int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d" ,&bard[i][j]);
        
    BFS(1,1);
    cout<<visited[n][m];
}