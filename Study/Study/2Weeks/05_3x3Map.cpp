#include <iostream>

using namespace std;

int dY[4] = {-1,0,1,0};
int dX[4] = {0,1,0,-1};
int map[3][3]{};
int visits[3][3]{};

void Solve(int y, int x)
{
    visits[y][x] = 1;
    cout<<y<<" : "<<x<<endl;
    for (int i = 0; i < 4; i++) 
    {
        int ny = y + dY[i];
        int nx = x + dX[i];
        if(ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
            continue;
        if(map[ny][nx] == 0)
            continue;
        if (visits[ny][nx] == 1)
            continue;

        Solve(ny, nx);
    }
}

int main()
{
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            cin>>map[i][j];
    map[0][0] = 1;
    Solve(0,0);
}