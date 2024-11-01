#include <iostream>

using namespace std;
int dp[104][2][34], n, m, b[104];
int go(int idx, int tree, int cnt)
{
	if (cnt < 0) 
		return -1e9;
	if (idx == n) 
		return 0;
	int& ret = dp[idx][tree][cnt];
	// �̹� ���� ���̸� ��ȯ
	if (ret != -1) 
		return ret;
	// ���� ������ �ӹ����ų� �ٸ� ������ �̵��ϴ� ��� �� �ִ� �� ����
	int a = go(idx + 1, tree ^ 1, cnt - 1);
	int d = go(idx + 1, tree, cnt);
	int c = (tree == b[idx] - 1);


	return ret = max(a, d + c);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> b[i];
	// �� ���� �ʱ� ����(1�� ������ ����, 2�� ������ ����) �� �ִ� �� ���
	cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
	return 0;
}