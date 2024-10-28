#include <iostream>
#include <queue>
using namespace std;

int dX[4] = {-1, 0, 1, 0}, dY[4] = {0, 1, 0, -1};
int n, m;
int x, y;
char Map[1001][1001];
bool JeHawn[1001][1001];
bool Fire[1001][1001];
queue<pair<int, int>> q;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 'F')
            {
                Fire[i][j] = true;
                q.push({i, j});
            }
            else if (Map[i][j] == 'J')
            {
                x = i;
                y = j;
            }
        }
    }

    while (q.empty() == false)
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nX = X + dX[i];
            int nY = Y + dY[i];
            if (nX < 0 || nX >= n || nY < 0 || nY >= m)
                continue;
            if (Fire[nX][nY] == true || Map[nX][nY] == '#')
                continue;
            Fire[nX][nY] = true;
            q.push({nX, nY});
        }
    }

    JeHawn[x][y] = true;
    q.push({x,y});
    while (q.empty() == false)
    {
        int nX = q.front().first;
        int nY = q.front().second;
        q.pop();
        if(nX == n-1 || nX == n|| nY == m-1)
    }
    
}