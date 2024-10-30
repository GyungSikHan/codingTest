#include <iostream>

using namespace std;

int dY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dX[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
    int y{}, x{};
    for (int i = 0; i < 8; i++) 
    {
        int ny = y + dY[i];
        int nx = x + dX[i];
        cout << ny << " : " << nx << endl;
    }
}