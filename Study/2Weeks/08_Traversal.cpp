#include <iostream>
#include <cstring>
#include <type_traits>
#include <vector>
using namespace std;

vector<int> adj[1004];
int visited[1004];
void postOrder(int here)
{ 
    if(visited[here] == true)
        return;
    
    visited[here] = true;
    
    for (auto a : adj[here]) 
        postOrder(a);
    
    cout<<here<<" ";
}
void preOrder(int here)
{ 
    if(visited[here] == true)
        return;
    visited[here] = true;
    cout<< here << " ";

    for (int a : adj[here]) 
        preOrder(a);
}
void inOrder(int here)
{ 
    if(visited[here] == true)
        return;
    if(adj[here].size() == 0)
    {
        cout<<here<<" ";
        return;
    }
    visited[here] = true;
    inOrder(adj[here][0]);
        cout<<here<<" ";
    if(adj[here].size() == 2)
        inOrder(adj[here][1]);

}
int main()
{ 
	adj[1].push_back(2); 
	adj[1].push_back(3); 
	adj[2].push_back(4); 
	adj[2].push_back(5); 
	int root = 1; 
	cout << "\n 트리순회 : postOrder \n";
	postOrder(root);
	memset(visited, 0, sizeof(visited));
	cout << "\n 트리순회 : preOrder \n"; preOrder(root);
	memset(visited, 0, sizeof(visited));
	cout << "\n 트리순회 : inOrder \n";
	inOrder(root);
	return 0; 
}
