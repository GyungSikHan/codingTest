#include <iostream>
#include <map>
#include <string>

using namespace std;

int t, n;
string a,b;

int main()
{
    cin>>t;
    while (t--) 
    {
        map<string, int> m;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>a>>b;
            m[b]++;
        }
        long long ret = 1;
        for (auto a: m) 
        {
            ret*= ((long long)a.second+1);
        }
        ret --;
        cout<<ret<<endl;
    }
}