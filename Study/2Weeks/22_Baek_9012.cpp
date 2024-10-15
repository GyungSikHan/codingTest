#include <iostream>

using namespace std;

int n;
string s;

int Solution()
{   
    int data{};
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            data++;
        else if(data == 0 && s[i] == ')')
        {
            data = 1;
            break;
        }        
        else if(s[i] == ')')
            data--;
    }
    
    return data;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;

        if(Solution() == 0)
            cout << "YES"<<endl;
        else
            cout << "NO"<<endl;
    }
    
}