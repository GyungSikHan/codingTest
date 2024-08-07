#include <iostream>
#include <cmath>
using namespace std;


long long Slove(long long a, long long b, long long c)
{
    if(b == 1)
        return a % c;

    long long restult = Slove(a,b/2,c);
    restult=(restult*restult)%c;
    if(b % 2 == 1)
        restult=(restult*a)%c;
    return restult;
}

int main()
{
    long long a,b,c;
    cin >> a>>b>>c;
    cout<<Slove(a,b, c)<<endl;
}