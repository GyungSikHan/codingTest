#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
char p;
char l;
char r;
char node[27][2];

void Preorder(char node[27][2], int i)
{

	cout << char(i+64);

	if(node[i][0] != '.')
		Preorder(node, i * 2);
	if(node[i][1] != '.')
		Preorder(node,  i * 2 + 1);
}

int main()
{
    cin>>n;

	for (int i = 1; i <= n; i++)
	{
		cin >> p >> l >> r;
		node[i][0] = l;
		node[i][1] = r;
	}

	Preorder(node, 1);
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << char(i + 64) << " " << node[i][0] << " " << node[i][1] << endl;
	//}
}