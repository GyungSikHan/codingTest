//#include <iostream>
//#include <vector>
//#include <queue>
//#include<math.h>
//using namespace std;
//
//int k;
//char arr[10];
//int visited[10];
//vector<int> v;
//vector<int> v2;
//vector<int> v3;
//int ret1; long long ret2 = 10000000000;
//
//bool oper(int a, int b, char c)
//{
//	if (c == '<')
//	{
//		if (a < b)
//			return true;
//	}
//	else if (c == '>')
//	{
//		if (a > b)
//			return true;
//	}
//
//	return false;
//}
//
//long long Make()
//{
//	long long temp{};
//	int index = k;
//	for (int a : v)
//	{
//		temp += a * pow(10 , index);
//		index--;
//	}
//
//	return temp;
//}
//
//void Go(int data, int index)
//{
//	if((int)v.size() == k+1)
//	{
//		long long temp = Make();
//		if(ret1 < temp)
//		{
//			ret1 = temp;
//			fill(v2.begin(), v2.begin() + (k + 1), 0);
//			for (int i = 0; i < k+1; i++)
//				v2[i] = v[i];
//		}
//		if(ret2 > temp)
//		{
//			ret2 = temp;
//			fill(v3.begin(), v3.begin() +( k + 1), 0);
//			for (int i = 0; i < k + 1; i++)
//				v3[i] = v[i];
//		}
//		return;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		if(data != i)
//		{
//			if(oper(data,i,arr[index]) == true)
//			{
//				if(visited[i] == 0)
//				{
//					v.push_back(i);
//					visited[i] = 1;
//					Go(i, index + 1);
//					v.pop_back();
//					visited[i] = 0;
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> k;
//	v2.resize(k + 1, 0);
//	v3.resize(k + 1, 0);
//	for (int i = 0; i < k; i++)
//		cin >> arr[i];
//
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//		visited[i] = 1;
//		Go(i, 0);
//		v.pop_back();
//		visited[i] = 0;
//	}
//
//	for (int i : v2)
//		cout << i;
//	cout << endl;
//	for (int i : v3)
//		cout << i;
//
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, check[10];
char arr[20];
vector<string> s;

bool good(char x, char y, char op)
{
	if (x < y && op == '<')
		return true;
	if (x > y && op == '>')
		return true;

	return false;
}

void Go(int index, string num)
{
	if(index == n+1)
	{
		s.push_back(num);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if(check[i] != 0)
			continue;
		if(index == 0 || good(num[index-1],i+'0',arr[index-1]))
		{
			check[i] = 1;
			Go(index + 1, num + to_string(i));
			check[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	Go(0, "");
	sort(s.begin(), s.end());
	cout << s[s.size() - 1] << "\n" << s[0] << endl;
}