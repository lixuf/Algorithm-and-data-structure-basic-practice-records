#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	node* left, *right;
	int val;
};
vector<int> num;
void build(node * & x,int n)
{
	if (n >= num.size())
	{
		x = NULL;
		return;
	}
	x = new(node);
	build(x->left, 2 * n);
	x->val = num[n];
	build(x->right, 2 * n + 1);
}
void levelorder(node * x)
{
	queue<node *> qu;
	qu.push(x);
	int nq = qu.size();
	while (!qu.empty())
	{
		node * mid = qu.front();
		qu.pop();
		cout << mid->val << " ";
		if (mid->left != NULL)
		{
			qu.push(mid->left);
		}
		if (mid->right != NULL)
		{
			qu.push(mid->right);
		}
		nq--;
		if (nq == 0)
		{
			nq = qu.size();
			cout << "\n";
		}
	}
	return;
}
int main()
{
	int n;
	cin >> n;
	num.push_back(0);
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		cin >> mid;
		num.push_back(mid);
	}
	sort(num.begin()+1, num.end());
	node * root;
	build(root,1);
	levelorder(root);
	system("pause");
	return 0;
}

/*
 ‰»Î
20
1 5 8 9 4 7 6 2 23 78 54 89 96 21 45 16 57 81 39 48
 ‰≥ˆ
1
2 4
5 6 7 8
9 16 21 23 39 45 48 54
57 78 81 89 96
*/