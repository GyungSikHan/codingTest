#include <iostream>

using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

int main()
{
    cin >> s;
    for (char c : s)    
        cnt[c]++;
    for (int i = 'Z'; i >= 'A'; i--)//오름차순으로 해야하기 때문에 Z~A로 차감하면서 비교
    {
        if(cnt[i] != 0)
        {
            if(cnt[i]%2 == 1)
            //if(cnt[i] & 1)//홀수라는 의미- 2진수에서 홀수는 맨 마지막 값이 무조건 1이므로
            {
                mid = char(i);
                flag++;
                cnt[i]--;
            }
            if(flag == 2)
                break;
            for (int j = 0; j < cnt[i]; j+=2) 
            {
                ret = char(i)+ret;
                ret += char(i);
            }
        }
    }

    if(mid != 0)
        ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag == 2)
        cout<<"I'm Sorry Hansoo\n";
    else
        cout<<ret<<"\n";
}