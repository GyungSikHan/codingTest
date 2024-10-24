#include <iostream>
#include <vector>

using namespace std;
int dX[4] = {-1,0,1,0}, dY[4] = {0,1,0,-1};
int n,l,r, days{}, sum;
int map[51][51];
bool visited[51][51];
vector<pair<int, int>> v;

void DFS(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nX = x + dX[i];
        int nY = y + dY[i];
        if(nX < 0 || nX >= n || nY < 0 || nY >= n || visited[nX][nY] == true)
            continue;
        int temp = abs(map[nX][nY] - map[x][y]);
        if(temp >= l && temp <= r)
        {
            visited[nX][nY] = true;
            v.push_back({nX, nY});
            sum += map[nX][nY];
            DFS(nX,nY);
        }
        
    }
    
}

int main()
{
    cin>>n>>l>>r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>map[i][j];

    while (true)
    {
        bool bFlag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(visited[i][j] == true)
                    continue;
                v.clear();
                visited[i][j] = true;
                v.push_back({i,j});
                sum = map[i][j];
                DFS(i,j);
                if(v.size() == 1)
                    continue;
                for (pair<int, int> p : v)
                {
                    map[p.first][p.second] = sum / v.size();
                    bFlag = true;
                }
            }
        }
        if(bFlag == false)
            break;
        days++;
    }
    
    cout<<days<<"\n";
}