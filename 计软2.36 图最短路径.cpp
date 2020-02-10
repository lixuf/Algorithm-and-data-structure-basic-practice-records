#include<iostream>
#include<vector>
using namespace std;
const int maxlen = 5;
vector<int> minroad;
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
void dfs(node * x, int targal,int path)
{
	if (x->num == (targal + 1))
	{
		if (path < minroad[targal])
		{
			minroad[targal] = path;
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
				dfs(x->next[n],targal, path + x->road[n]);
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
	}
	for(int n1=1;n1<n;n1++)
	{ 
		dfs(map[0], n1,0);
	}
	for (int n1 = 1; n1 < n; n1++)
	{
		cout << "到" << n1 + 1 << "最小路径" << minroad[n1] << "\n";
	}
	system("pause");
	return 0;
}

/*
输入
8
2 2 2 3 3
2 1 2 4 2
2 1 3 4 1
4 2 2 5 2 6 4 3 1
3 7 2 6 1 4 2
4 4 4 5 1 7 2 8 1
3 5 2 6 2 8 3
2 6 1 7 3
输出
2-8 为 b-h
到2最小路径2
到3最小路径3
到4最小路径4
到5最小路径6
到6最小路径7
到7最小路径8
到8最小路径8
*/