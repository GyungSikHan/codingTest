#include <iostream>
#include <queue>
using namespace std;

int n,m;
int startY,startX;
int endY,endX;
int maps[104][104];
int visited[104][104];
int arY[4] = {-1,0,1,0};
int arX[4] = {0,1,0,-1};

queue<pair<int, int>> q;

void DFS(int y, int x)
{
    visited[y][x] = 1;
    q.push({y,x});

    while (q.empty() == false ) 
    {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int Y = currY + arY[i];
            int X = currX + arX[i];
            if(Y >= 0 && y < n && X >= 0 && X < m)
            {
                if(maps[Y][X] == 1 && visited[Y][X] == 0)
                {
                    visited[Y][X] = visited[currY][currX]+1;
                    q.push({Y,X});
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    cin>>startY>>startX;
    cin>>endY>>endX;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin>>maps[i][j];

    DFS(0,0);
    cout<< visited[endY][endX] <<endl;
}