#include <iostream>
#include <vector>
using namespace std;

int n,o,A,B, aSum, bSum;
string s, sPrev;

string print(int a)
{ 
    string d = "00" + to_string(a / 60); 
    string e = "00" + to_string(a % 60); 
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}

int ChangeToInt(string a)
{
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}
void Go(int& sum, string s)
{
    sum+= ChangeToInt(s) - ChangeToInt(sPrev);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>> o >> s;
        if(A>B)
            Go(aSum, s);
        else if(B>A)
            Go(bSum, s);
        o == 1 ? A++ : B++;
        sPrev = s;
    }

    if(A > B)
    Go(aSum, "48:00");
    else if(B > A)
    Go(bSum, "48:00"); 
    cout << print(aSum) << "\n"; 
    cout << print(bSum) << "\n";
}