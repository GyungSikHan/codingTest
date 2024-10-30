#include <iostream>
#include <algorithm>
using namespace std;

string S;
string temp;
bool b;
int main()
{
  cin>>S;
  temp = S;
  reverse(temp.begin(), temp.end());

  if(temp == S)
    b=true;

  cout << b << endl;
}