#include <iostream>
#include <string.h>

using namespace std;

int depth{};

int recursion(const char* s, int l, int r)
{
	depth++;
    if (l >= r) 
        return 1;
    else if(s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s)
{
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t{};
    string s{};
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        cout << isPalindrome(s.c_str()) << " " << depth << endl;
        ///c_str() 함수는 const char*를 리턴해준다
        depth = 0;
    }
}