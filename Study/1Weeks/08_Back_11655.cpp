#include <iostream>
#include <string>
using namespace std;

string S;
int main()
{
    getline(cin, S);

    for (int i = 0; i < S.size(); i++)
    {
        if(S[i] >= 65 && S[i] <= 90)
        {
            if(S[i]+13 > 90)
                S[i] = S[i] + 13 - 26;
            else
                S[i] +=13;
        }
        if(S[i] >= 97 && S[i] <= 122)
        {
            if(S[i]+13 > 122)
                S[i] = S[i] + 13 - 26;
            else
                S[i] +=13;
        }
    }

    cout<<S<<endl;
}