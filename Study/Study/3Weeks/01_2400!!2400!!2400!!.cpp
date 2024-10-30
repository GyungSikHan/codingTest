#include<iostream>

using namespace std;

int n,number;
int lalo = 2400;
int main()
{
    cin >> n;
    while (true)
    {
        string a = to_string(lalo);
        if(a.find("2400") != string::npos)
        {
            number++;
            if(n == number)
            {
                cout<< a <<endl;
                break;
            }
        }
        lalo++;
    }
    
}