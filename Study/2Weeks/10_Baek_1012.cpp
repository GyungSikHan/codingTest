#include<iostream>
#include<vector>

using namespace std;

int T, M,N,K;

int dY[4]{-1,0,1,0};
int dX[4]{0,1,0,-1};      

int maps[51][51]{};
bool visited[51][51]{};

void DFS(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int Y = y + dY[i];
        int X = x + dX[i];

        if(Y >= 0 && Y < N && X >= 0 && X < M)
        {
            if(maps[Y][X] == 1 && visited[Y][X] == false)
                DFS(Y,X);
        }
    }
}

int main()
{
    cin>>T;

    while (T--)
    {
        cin>>M>>N>>K;
        int count{};
        fill(&maps[0][0], &maps[0][0]+51*51, 0);
        fill(&visited[0][0], &visited[0][0]+51*51, false);
        
        for (int i = 0; i < K; i++)
        {
            int x{},y{};
            cin>>x>>y;
            maps[y][x] = 1;
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(maps[i][j] == 1 && visited[i][j] == false)
                {
                    DFS(i,j);
                    count++;
                }
            }
            
        }
        cout<<count<<endl;
    }
}