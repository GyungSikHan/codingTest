#include <iostream>

using namespace std;

int N;
int arr[26];
string S;
string S2;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin>>S;

        arr[S[0] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if(arr[i] >= 5)
            S2+=i+'a';
    }   

    if(S2.size() == 0)
        S2 = "PREDAJA";
        
    cout << S2 <<endl;
}