#include <iostream>

using namespace std;

int N{};
char arr[65][65];
string S{};

string DFS(int y, int x, int k)
{
    if(k == 1)
        return string(1, arr[y][x]);
    char temp = arr[y][x];
    string result{};
    
    for (int i = y; i < y+k; i++)
    {
        for (int j = x; j < x+k; j++)
        {
            if(temp != arr[i][j])
            {
                result += '(';
                result += DFS(y,x,k/2);
                result += DFS(y,x+k/2,k/2);
                result += DFS(y+k/2,x,k/2);
                result += DFS(y+k/2,x+k/2,k/2);
                result += ')';
                return result;
            }
        }   
    }
    
    return string(1, arr[y][x]);
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin>>S;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = S[j];
        }
    }   
        
    cout<<DFS(0,0,N)<<endl;
}
//범위가 쪼개져서 반복한다 == 재귀