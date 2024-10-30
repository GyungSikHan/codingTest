#include <iostream>

using namespace std;

const int dY[4] = {-1, 0, 1, 0};
const int dX[4] = {0, 1, 0, -1};

int main() 
{
    int y{}, x{};
    for (int i = 0; i < 4; i++) 
    {
        int ny = y + dY[i];
        int nx = x + dX[i];
        cout << ny << " : " << nx << endl;
    }
}