#include <iostream>
#include <string.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> Trust;
int Visit[100001];
int Result[10001];
int n, m;
int A,B;
int Max;

int DFS(int index)
{
    Visit[index] = 1;
    int count = 1;
    for (int i : Trust[index])
    {
        if(Visit[i] == 0)
            count += DFS(i);
    }

    return count;
}

int main()
{
    cin>>n>>m;
    Trust.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        cin >> A >> B;
        Trust[B].push_back(A);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(Visit, 0, sizeof(Visit));
        Result[i] = DFS(i);
        Max = max(Result[i], Max);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(Result[i] == Max)
            cout<<i << " ";
    }
    
}