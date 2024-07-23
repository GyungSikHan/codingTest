#include <iostream>
#include<vector>
using namespace std;

int n;
int m;
vector<int> arr;
vector<int> arr2;

int main()
{
    cin >> n >> m;
    arr.resize(n+1, 0);
    arr2.resize(n+1, 0);
    for (int i = 1; i <= n; i++)
    {        
        cin >> arr[i];
        if(i == 1)
            arr2[i] = arr[i];
        else
            arr2[i] = arr2[i-1] + arr[i];
    }   

    int start{}, end{};

    for (int i = 0; i < m; i++)
    {
        cin>>start>>end;
        cout << arr2[end] - arr2[start-1] << endl;
    }

}