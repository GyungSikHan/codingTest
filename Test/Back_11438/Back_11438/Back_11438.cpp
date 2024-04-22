#pragma warning(disable:4996)
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 100001;
const int MAXK = 17; // log2(MAXN) + 1

vector<vector<int>> Tree;
vector<int> Depth;
vector<vector<int>> Parent;

void DFS(int node, int parent, int depth) {
    Depth[node] = depth;
    Parent[node][0] = parent;

    for (int i = 1; i < MAXK; ++i) {
        int prev_parent = Parent[node][i - 1];
        Parent[node][i] = Parent[prev_parent][i - 1];
    }

    for (int child : Tree[node]) {
        if (child != parent) {
            DFS(child, node, depth + 1);
        }
    }
}

int LCA(int a, int b) {
    if (Depth[a] < Depth[b])
        swap(a, b);

    int diff = Depth[a] - Depth[b];

    for (int i = 0; i < MAXK; ++i) {
        int a = 1 << i;
        if (diff & (a)) 
        {
            a = Parent[a][i];
        }
    }

    if (a == b)
        return a;

    for (int i = MAXK - 1; i >= 0; --i) {
        if (Parent[a][i] != Parent[b][i]) {
            a = Parent[a][i];
            b = Parent[b][i];
        }
    }

    return Parent[a][0];
}

int main() {
    int n;
    scanf("%d", &n);

    Tree.resize(n + 1);
    Depth.resize(n + 1);
    Parent.resize(n + 1, vector<int>(MAXK));

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }

    DFS(1, 0, 0);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", LCA(u, v));
    }

    return 0;
}