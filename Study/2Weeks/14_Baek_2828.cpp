#include <iostream>

using namespace std;

int n, m;
int j;
int start;
int end;
int apple;
int result;

int  main()
{
    cin>>n>>m;
    cin>>j;

    start = 1;

    for (int i = 0;i < j;i++)
    {
        length = m + start - 1;
        cin>> apple;

        if(apple < start || apple > length)
        {
            if(apple < start)
            {
                result += (start - apple);
                start = apple;
            }
            else
            {
                start += apple - length;
                result += apple - length;
            }
        }
    }
    
    cout<<result<<endl;
}