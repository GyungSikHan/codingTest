#include <iostream>
#include <vector>
using namespace std;

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0 , 1 ,0 ,-1};

int Map[3][3]{
    10, 20, 21,
    70, 90, 12,
    80, 110, 120
    };
bool Visited[3][3];
vector<int> V;

void Print()
{
    for(int i : V)
        cout<<i<<" ";
    cout<<endl;
}

void Go(int x, int y)
{
    if(x == 2 && y == 2)
    {
        Print();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nX = x+dX[i];
        int nY = y+dY[i];
        if(nX >= 0 && nX < 3 && nY >= 0 && nY < 3)
        {
            if(Visited[nX][nY] == false)
            {
                Visited[nX][nY] = true;
                V.push_back(Map[nX][nY]);
                Go(nX,nY);
                
                Visited[nX][nY] = false;
                V.pop_back();
            }
        }
    }
    

}

int main()
{
    Visited[0][0] = true;
    V.push_back(Map[0][0]);
    Go(0,0);    
}