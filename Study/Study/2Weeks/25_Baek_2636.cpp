#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int nX[4] = {-1,0,1,0};
int nY[4] = {0,1,0,-1};

int n, m;
int Time;
int Chees;
int Map[100][100];
int Visited[100][100];
vector<pair<int, int>> vP;

void DFS(int x, int y)
{
    Visited[x][y] = 1;
    if(Map[x][y] == 1)
    {
        vP.push_back(make_pair(x,y));
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int dx = x+nX[i];
        int dy = y+nY[i];
        if(dx >= 0 && dx < n && dy >= 0 && dy < m && Visited[dx][dy] == 0)
            DFS(dx,dy);
    }
    
}

int main()
{
    cin>>n>>m;
   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>Map[i][j];

    while (true)
    {
        memset(Visited,0,sizeof(Visited));
        vP.clear();
        DFS(0,0);
        Chees = vP.size();
        for(auto a : vP)
            Map[a.first][a.second] = 0;
        bool bFlag{};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(Map[i][j] == 1)
                    bFlag = true;

        Time++;
        if(bFlag == false)
            break;
    }
    
    cout << Time << endl;
    cout << Chees << endl;
    
}