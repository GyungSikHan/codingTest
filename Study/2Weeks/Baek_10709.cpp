#include <iostream>
#include <vector>
using namespace std;

int h,w;
char c;
bool bC;
int Data{};

int main()
{
    cin >> h >> w;
    vector<vector<int>> v(h,vector<int>(w, 0));


    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {

            cin >> c;
            if(c == 'c')
            {
                bC = true;
                Data = 0;
            }
            else if(bC == true)
                Data++;
            else if(bC == false)
                Data = -1;
            v[i][j] = Data;
        }  
        Data = 0;
        bC = false;
    }
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}