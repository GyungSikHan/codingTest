#include<iostream>
#include <stack>
using namespace std;
string s;
char c;

bool Solution()
{
    bool b{};
    stack<char> st{};
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else if(s[i] == ')')
        {
            if(st.empty() == false && st.top() == '(')
                st.pop();
            else
            {
                b = true;
                break;
            }
        }
        else if(s[i] == ']')
        {
            if(st.empty() == false && st.top() == '[')
                st.pop();
            else
            {
                b = true;
                break;
            }
        }
    }


    if(b == false && st.empty() == true)
        b = false;
    else
        b = true;
    return b;
}

int main()
{
    while (true)
    {
        getline(cin, s);
        if(s == ".")
            break;
        if(Solution() == false)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}