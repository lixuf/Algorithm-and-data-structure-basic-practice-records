#include<iostream>
#include<vector>
using namespace std;
const int maxlen = 5;
vector<int> minroad;
vector<int> maxroad;
vector<int> flag;
struct node
{
	node * next[maxlen];
	int road[maxlen];
	int num;
};
void init(node *& x)
{
	for (int n = 0; n < maxlen; n++)
	{
		x->next[n] = NULL;
		x->road[n] = 0;
	}
}
void dfs(node * x, int targal, int path)
{
	if (x->num == (targal + 1))
	{
		if (path < minroad[targal])
		{
			minroad[targal] = path;
		}
		if (path > maxroad[targal])
		{
			maxroad[targal] = path;
		}
		return;
	}
	flag[x->num - 1] = 1;
	for (int n = 0; n < maxlen; n++)
	{
		if (x->next[n] != NULL)
		{
			if (flag[x->next[n]->num - 1] == 0)
			{
				dfs(x->next[n], targal, path + x->road[n]);
			}
		}
	}
	flag[x->num - 1] = 0;
	return;
}
int main()
{
	int  n;
	cin >> n;
	vector<node*> map;
	for (int n1 = 0; n1 < n; n1++)
	{
		node *mid = new(node);
		init(mid);
		mid->num = n1 + 1;
		map.push_back(mid);
		flag.push_back(0);
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		cin >> mid;
		for (int n2 = 0; n2 < mid; n2++)
		{
			int midn, midr;
			cin >> midn >> midr;
			map[n1]->next[n2] = map[midn - 1];
			map[n1]->road[n2] = midr;
		}
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		minroad.push_back(999);
		maxroad.push_back(0);
	}
	for (int n1 = 1; n1 < n; n1++)
	{
		dfs(map[0], n1, 0);
	}
	for (int n1 = 1; n1 < n; n1++)
	{
		cout <<  n1 + 1 << "  最早开始时间：" << minroad[n1] << "  最晚开始时间：" << maxroad[n1] << "\n";
	}
	cout << "最早完成时间：" << minroad[n - 1];
	system("pause");
	return 0;
}

/*
输入nr
10
2 2 5 3 6
1 4 3
2 4 6 5 3
3 6 4 7 4 5 7
2 7 1 8 4
1 10 4
1 9 5
1 9 2
1 10 2
0
输出
2  最早开始时间：5  最晚开始时间：5
3  最早开始时间：6  最晚开始时间：6
4  最早开始时间：8  最晚开始时间：12
5  最早开始时间：9  最晚开始时间：19
6  最早开始时间：12  最晚开始时间：16
7  最早开始时间：10  最晚开始时间：20
8  最早开始时间：13  最晚开始时间：23
9  最早开始时间：15  最晚开始时间：25
10  最早开始时间：16  最晚开始时间：27
最早完成时间：16
*/