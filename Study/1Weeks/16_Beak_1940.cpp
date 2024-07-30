#include <iostream>

using namespace std;

int n, m;
int arr[15001];
int Count;

int main() 
{
  cin >> n;
  cin >> m;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (arr[i] + arr[j] == m)
          Count++;
    cout << Count << endl;
}