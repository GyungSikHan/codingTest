#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> tree;

void init_tree(vector<long long>& arr) {
    // Leaf 노드에 입력값 할당
    for (int i = 0; i < n; ++i)
        tree[n + i] = arr[i];

    // 부모 노드로 올라가면서 합 구하기
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

// 구간 합 구하기
long long query(int l, int r) {
    long long res = 0;
    // 구간의 왼쪽 끝과 오른쪽 끝이 같아질 때까지 반복
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += tree[l++]; // 왼쪽 끝이 홀수이면 현재 값을 더하고 오른쪽으로 이동
        if (r & 1) res += tree[--r]; // 오른쪽 끝이 홀수이면 현재 값을 더하고 왼쪽으로 이동
    }
    return res;
}

void update(int i, long long val) {
    // i 위치의 값을 val로 갱신하고 이에 따라 부모 노드 업데이트
    for (tree[i += n] = val; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] + tree[i ^ 1];
}

int main() {
    int m, k;
    cin >> n >> m >> k;

    // 트리의 크기 설정
    int sz = 1;
    while (sz < n) sz <<= 1;
    tree.assign(sz * 2, 0);

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // 세그먼트 트리 초기화
    init_tree(arr);

    for (int i = 0; i < m + k; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        }
        else if (a == 2) {
            cout << query(b - 1, c) << endl;
        }
    }
    return 0;
}
