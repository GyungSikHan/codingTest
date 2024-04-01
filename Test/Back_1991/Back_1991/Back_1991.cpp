#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int Tree[27][2];

void Preorder(int n)
{
	cout << (char)(n + 'A');

	if (Tree[n][0] != -1)
		Preorder(Tree[n][0]);
	if (Tree[n][1] != -1)
		Preorder(Tree[n][1]);
}

void Inorder(int n)
{
	if (Tree[n][0] != -1)
		Inorder(Tree[n][0]);
	cout << (char)(n + 'A');
	if(Tree[n][1] != -1)
		Inorder(Tree[n][1]);
}

void Postorder(int n)
{
	if (Tree[n][0] != -1)
		Postorder(Tree[n][0]);
	if (Tree[n][1] != -1)
		Postorder(Tree[n][1]);
	cout << (char)(n + 'A');
}

int main()
{
    cin >> n;

	for (int i = 0; i < n; i++)
	{
		char s{}, l{}, r{};
		cin >> s >> l >> r;

		int node = s - 'A';

		if (l == '.')
			Tree[node][0] = -1;
		else
			Tree[node][0] = l - 'A';
		if (r == '.')
			Tree[node][1] = -1;
		else
			Tree[node][1] = r - 'A';
	}

	Preorder(0);
	cout<<endl;
	Inorder(0);
	cout<<endl;
	Postorder(0);
}