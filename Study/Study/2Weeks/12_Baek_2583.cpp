#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m,n,k;
int arr[101][101];
int visited[101][101];
int y1,y2,x1,x2;

int arrY[4] = {-1,0,1,0};
int arrX[4] = {0,1,0,-1};
int Count = 1;
vector<int> v;

void Space()
{
    for (int i = y1; i < y2; i++)
    {
        for (int j = x1; j < x2; j++)
        {
            arr[i][j] = 1;
        }
    }
}

void DFS(int y,int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int Y = y+arrY[i];
        int X = x+arrX[i];

        if(Y >= 0 && Y < m && X >= 0 && X < n)
            if(arr[Y][X] == 0 && visited[Y][X] == false)
            {
                Count++;
                DFS(Y, X);
            }
    }
    

}

int main()
{
    cin >> m >> n >> k;

    for(int i = 0; i < k; i++)
    {
        cin >> x1>>y1>>x2>>y2;
        Space();
    }

    for (int i = m-1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0 && visited[i][j] == false)
            {
                DFS(i,j);
                v.push_back(Count);
            }
            Count = 1;
        }
    }
    
    sort(v.begin(), v.end());
    cout << v.size()<<endl;
    for (int iter : v)
        cout << iter << " ";

    
}