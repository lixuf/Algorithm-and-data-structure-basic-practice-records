#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxlen = 5;
vector<int> flag;
struct node
{
	int num;
	node * next[maxlen];
};

void init(node * & x)
{
	for (int n = 0; n < maxlen; n++)
	{
		x->next[n] = NULL;
	}
	return;
}

void DFS(node * x)
{
	if (flag[x->num - 1] == 0)
	{
		cout << x->num << " ";
		flag[x->num - 1] = 1;
		for (int n = 0; n < maxlen; n++)
		{
			if (x->next[n] != NULL)
			{
				if (flag[x->next[n]->num - 1] == 0)
				{
					DFS(x->next[n]);
				}
			}
		}
		return;
	}
	
}

void BFS(node * x)
{
	queue<node*> bfs;
	bfs.push(x);
	flag[x->num - 1] = 0;
	while (!bfs.empty())
	{
		node * mid = bfs.front();
		bfs.pop();
		cout << mid->num <<" ";
		for (int n = 0; n < maxlen; n++)
		{
			if (mid->next[n] != NULL)
			{
				if (flag[mid->next[n]->num - 1] == 1)
				{
					flag[mid->next[n]->num - 1] = 0;
					bfs.push(mid->next[n]);
				}
			}
		}
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	vector<node *> map;
	for (int n1 = 0; n1 < n; n1++)
	{
		node *  mid = new (node);
		init(mid);
		mid->num = n1 + 1;
		map.push_back(mid);
		flag.push_back(0);
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		int n2;
		cin >> n2;
		for (int n3 = 0; n3 < n2; n3++)
		{
			int mid;
			cin >> mid;
			map[n1]->next[n3] = map[mid - 1];
		}
	}
	DFS(map[0]);//v1=1
	cout << "\n";
	BFS(map[0]);//v1=1
	system("pause");
	return 0;
}
/*
ÊäÈë
20
3 2 8 5
3 1 10 3
3 2 12 4
3 3 5 14
3 1 6 4
3 5 7 15
3 6 17 8
3 7 9 1
3 10 8 18
3 11 2 9
3 12 19 10
3 11 13 3
3 12 20 14
3 13 15 4
3 16 14 6
3 20 17 15
3 18 16 7
3 9 19 17
3 11 20 18
3 19 13 16
Êä³ö
dfs 1 2 10 11 12 13 20 19 18 9 8 7 6 5 4 3 14 15 16 17
bfs 1 2 8 5 10 3 7 9 6 4 11 12 17 18 15 14 19 13 16 20
*/