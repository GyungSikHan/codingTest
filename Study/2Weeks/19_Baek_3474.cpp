#include <iostream>
#include <algorithm>
using namespace std;

int T;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        cin>>N;
        int ret{},ret2{};
        for (int j = 2; j <= N; j*=2)
            ret += N/j;
        for (int j = 5; j <= N; j*=5)
            ret2 += N/j;
        
        cout<<min(ret, ret2)<<"\n";
    }
    
}