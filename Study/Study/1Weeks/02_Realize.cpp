#include <iostream>
#include <algorithm>
using namespace std;

string dopa = "umzunsik";

int main()
{
    cout << dopa.substr(0,3)<<endl;//substr 함수는 첫번째 매개 변수의 index부터 두번째 매개변수의 index까지 출력해주는 함수
    reverse(dopa.begin(), dopa.end());//algorthm 안에 있는 reverse함수는 문자열을 앞뒤를 바꿔주는 함수이다
    cout << dopa <<endl;
    dopa+="umzunsik";
    cout << dopa << endl;
}