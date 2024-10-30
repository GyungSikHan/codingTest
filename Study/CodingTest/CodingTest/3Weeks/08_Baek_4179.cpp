#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
int dX[4] = { -1,0,1,0 }, dY[4] = { 0,1,0,-1 };
int r,c,jX, jY;
char map[1001][1001];
int fire[1001][1001], J[1001][1001];
int result;

bool In(int x, int y)
{
    return x >= 0 && x < r && y >= 0 && y < c;
}

int main()
{
    cin >>r>>c;

	queue<pair<int, int>> q;
    fill(&fire[0][0], &fire[0][0] + 1001 * 1001, INF);

	for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'F')
            {
                fire[i][j] = 1;
                q.push({ i,j });
            }
            else if (map[i][j] == 'J')
            {
                jX = i;
                jY = j;
            }
        }
    }

    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nX = x + dX[i];
            int nY = y + dY[i];
	        if(In(nX,nY) == false)
	            continue;
	        if(fire[nX][nY] != INF || map[nX][nY] == '#')
	            continue;
	        fire[nX][nY] = fire[x][y] + 1;
            q.push({ nX,nY });
        }
    }


    J[jX][jY] = 1;
    q.push({ jX,jY });

    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if(x == 0 || x == r-1 || y == 0 || y == c-1)
        {
            result = J[x][y];
	        break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nX = x + dX[i];
            int nY = y + dY[i];
            if(In(nX,nY) == false)
                continue;
            if(J[nX][nY] || map[nX][nY] == '#')
                continue;
            if(fire[nX][nY] <= J[x][y] +1)
                continue;
            J[nX][nY] = J[x][y] + 1;
            q.push({ nX,nY });
        }
    }

    if (result != 0)
        cout << result << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    
}