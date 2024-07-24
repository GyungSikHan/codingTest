#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[9]{};
int sum{};

void Solve()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if(sum - arr[i] - arr[j] == 100)
            {
                for (int k = 0; k < 9; k++)
                    if(i != k && j != k)
                        cout << arr[k] << endl;

                return;
            }
        }
        
    }
}

int main()
{

    for (int i = 0; i < 9; i++)
    {
        cin>>arr[i];
        sum+=arr[i];    
    }   
    
    sort(arr, arr+9);
    Solve();
}