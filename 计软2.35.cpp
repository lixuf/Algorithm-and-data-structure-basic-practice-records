2.35
#include<vector>
#include<iostream>
using namespace std;
const int maxlen = 5;
struct node	
{
	int in, out;
	int num;
	node * next[maxlen];
};
void init(node * &x)
{
	x->in = 0;
	x->out = 0;
	for (int n = 0; n < maxlen; n++)
	{
		x->next[n] = NULL;
	}
	return;
}
int main()
{
	vector<node *> map;
	int n;
	cin >> n;
	for (int n1 = 0; n1 < n; n1++)
	{
		node * mid = new(node);
		init(mid);
		mid->num = n1 + 1;
		map.push_back(mid);
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		cin >> mid;
		for (int n2 = 0; n2 < mid; n2++)
		{
			int mid1;
			cin >> mid1;
			map[n1]->next[n2] = map[mid1 - 1];
		}
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		for (int n2 = 0;n2<maxlen; n2++)
		{
			if (map[n1]->next[n2] != NULL)
			{
				map[n1]->next[n2]->in += 1;
				map[n1]->out += 1;
			}
		}
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		cout <<n1+1<< "  入度：" << map[n1]->in << "  出度：" << map[n1]->out << "\n";
	}
	system("pause");
	return 0;
}

/*
输入
6
0
2 1 4
2 2 6
2 5 3
1 1
4 1 2 5 4
输出
1  入度：3  出度：0
2  入度：2  出度：2
3  入度：1  出度：2
4  入度：2  出度：2
5  入度：2  出度：1
6  入度：1  出度：4
*/
