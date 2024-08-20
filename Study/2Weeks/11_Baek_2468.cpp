#include<iostream>

using namespace std;

int dY[4] = {-1,0,1,0};
int dX[4] = {0,1,0,-1};
int n;
int arr[105][105];
bool visited[105][105];
int MaxData;
int MaxCount;

void DFS(int y, int x, int k)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int Y = y + dY[i];
        int X = x + dX[i];
        if(Y >= 0 && Y < n && X >= 0 && X < n)
        {
            if(arr[Y][X] > k && visited[Y][X] == false)
                DFS(Y,X ,k);
        }
    }
}

int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            {
                int temp;
                cin >>temp;
                arr[i][j] = temp;
                MaxData = max(MaxData, temp);
            }

    for (int k = 0; k < MaxData; k++)
    {
        int count{};
        fill(&visited[0][0], &visited[0][0] + 105*105, false);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(visited[i][j] == false &&arr[i][j] > k)
                {
                    count++;
                    DFS(i,j, k);
                }
            }
        }
        MaxCount = max(count , MaxCount);
    }
    
    cout<<MaxCount<<endl;
}