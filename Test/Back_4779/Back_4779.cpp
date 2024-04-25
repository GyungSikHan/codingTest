﻿#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// 칸토어 집합 생성 함수
string cantorSet(int n, int start, int end) {
    if (n == 0) {
        return "-";
    }

    int length = end - start;
    int interval = length / 3;

    string result = cantorSet(n - 1, start, start + interval);
    result += string(interval, ' ');
    result += cantorSet(n - 1, end - interval, end);

    return result;
}

int main() {
    int n;
    while (cin >> n) 
    {
        int size = pow(3, n);
        string cantor = cantorSet(n, 0, size);

        cout << cantor << endl;
    }

    return 0;
}
