#include <iostream>

using namespace std;

int n, m;
int j;
int Start;
int End;
int apple;
int result;

int  main()
{
    cin>>n>>m;
    cin>>j;

    Start = 1;

    for (int i = 0;i < j;i++)
    {
        End = m + Start - 1;
        cin>> apple;

        if(apple < Start)
        {
            result += (Start - apple);
            Start = apple;
        }
        else if(apple > End)
        {
            Start += apple - End;
            result += apple - End; 
        }
    }
    
    cout<<result<<endl;
}