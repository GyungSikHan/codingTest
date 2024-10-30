#include <iostream>
#include <stack>
using namespace std;

int n;
int Count;
string S;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> S;
        stack<char> s{};
        for (char c : S)
        {
            if (s.empty() == false && s.top() == c)
                s.pop();
            else 
                s.push(c);
            
        }
        if (s.empty() == true)
        Count++;
    }
    cout << Count << endl;
}
