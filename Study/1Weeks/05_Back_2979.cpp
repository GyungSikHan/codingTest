#include <iostream>

using namespace std;

int A,B,C;
int a,b;
int arr[101];
int ret;

int main()
{
    cin>>A>>B>>C;

    for (int i = 0; i < 3; i++)
    {
        cin>>a>>b;
        for (int j = a; j < b; j++)
            arr[j]++;
    }

    for (int i = 0; i < 100; i++)
    {
        if(arr[i] == 0)
            continue;
        else if(arr[i] == 1)
            ret+=A;
        else if(arr[i] == 2)
            ret+=B*2;
        else if(arr[i] == 3)
            ret+=C*3;
    }
    
    cout<<ret<<endl;
}