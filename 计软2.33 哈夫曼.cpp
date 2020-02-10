#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	node * left,* right;
	int weight;
	int p;
};
int n_weight(node * x,int y)
{
	if (x->left == NULL && x->right == NULL)
	{
		return y * x->weight;
	}
	return n_weight(x->right, y + 1)+ n_weight(x->left, y + 1);
}
bool cmp(node * a, node * b)
{
	if (a->p == b->p)
	{
		return a->weight< b->weight;
	}
	else
	{
		return a->p < b->p;
	}
}
void levelorder(node * x)
{
	queue<node *> level;
	level.push(x);
	int n = level.size();
	while (!level.empty())
	{
		node * mid = level.front();
		level.pop();
		cout << mid->weight << " ";
		n--;
		if (mid->left != NULL)
		{
			level.push(mid->left);
		}
		if (mid->right!= NULL)
		{
			level.push(mid->right);
		}
		if (n == 0)
		{
			cout << "\n";
			n = level.size();
		}
	}
	return;
}
int main()
{
	int n;
	cin >> n;
	vector<node *> hfm;
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		cin >> mid;
		node * mid2 = new(node);
		mid2->left = NULL;
		mid2->right = NULL;
		mid2->weight = mid;
		mid2->p = 0;
		hfm.push_back(mid2);
	}
	for (int n1 = 0; n1 < n-1; n1++)
	{
		sort(hfm.begin(), hfm.end(), cmp);
		hfm[0]->p = 1;
		hfm[1]->p = 1;
		node * mid = new(node);
		mid->left = hfm[0];
		mid->right = hfm[1];
		mid->p = 0;
		mid->weight = n_weight(mid,1);
		hfm.push_back(mid);
	}

	for (int n1 = 0; n1 < hfm.size(); n1++)
	{
		if (hfm[n1]->p == 0)
		{
			levelorder(hfm[n1]);
			break;
		}
	}
	
	system("pause");
	return 0;

}
/*
 ‰»Î
7
8 2 5 3 2 17 4
 ‰≥ˆ
147
33 73
8 14 17 26
2 2 3 4 5 8
*/