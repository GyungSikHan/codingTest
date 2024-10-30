#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int n, m;
int arr[1000001];
int Result[1000001];
stack<int> S;

int main()
{
    cin >> n;
	memset(Result, -1, sizeof(Result));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while (S.size() != 0 && arr[S.top()] < arr[i])
        {
            Result[S.top()] = arr[i];
            S.pop();
        }
        S.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << Result[i] << " ";
    }

}
