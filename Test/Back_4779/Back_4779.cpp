#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string Cantor(int data, int start, int end)
{
    if(data == 0)
        return "-";

    int length = end - start;
    int interval = length/3; 

    string result = Cantor(data-1, start, start + interval);
    for(int i = 0; i < interval; i++)
    {
        result += " ";
    }
    result += Cantor(data-1, end - interval, end);

    return result;
}

int main()
{
    int n{};

    while(1)
    {
        cin >> n;

        int data = pow(3,n);

        string s = Cantor(n, 0, data);
        cout << s << endl;
    }
}