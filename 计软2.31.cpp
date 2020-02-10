#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int n = 10;//node数
vector<int> init_val;

struct node
{
	node * left;
	node * right;
	int val;
};

vector<int> preorder, inorder, postorder,levelorder;
int n1, n2;//树order长度
int index = 0;
int leave_count = 0;//叶子节点个数
int maxdeep = 0;//最大深度

void order_c(node * root,int deep)///带计算各参数的order
{
	if (root == NULL)
	{
		return;
	}
	preorder.push_back(root->val);
	order_c(root->left,deep);
	inorder.push_back(root->val);
	order_c(root->right,deep);
	postorder.push_back(root->val);
	if (root->right == NULL && root->left == NULL)
	{
		leave_count += 1;

	}
	
}

void order(node * root)///不带计算各参数的order
{
	if (root == NULL)
	{
		return;
	}

	preorder.push_back(root->val);
	order(root->left);
	inorder.push_back(root->val);
	order(root->right);
	postorder.push_back(root->val);
}

void bfs(node * root)
{
	cout << root ->val << "\n";
	queue<node *> mid2;
	mid2.push(root);
	int n;
	while (!mid2.empty())
	{
		n = mid2.size();
		while (n--)
		{
			node * mid3 = mid2.front();
			mid2.pop();
			if (mid3->left != NULL)
			{
				levelorder.push_back(mid3->left->val);
				cout << mid3->left->val<<" ";
				mid2.push(mid3->left);
			}
			if (mid3->right != NULL)
			{
				levelorder.push_back(mid3->right->val);
				cout << mid3->right->val<<" ";
				mid2.push(mid3->right);
			}
		}
		cout << "\n";
		maxdeep += 1;

	}
}

void copy(node * & root_c, node * root)
{
	if (root == NULL)
	{
		root_c = NULL;
		return;
	}
	root_c = new (node);
	root_c->val = root->val;
	copy(root_c->left, root->left);
	copy(root_c->right, root->right);
}
bool j_eq()
{
	if (n1 != n2)
	{
		return false;
	}
	for (int n3 = 0; n3 < n1; n3++)
	{
		if (inorder[n3] != inorder[n3 + n1])
		{
			return false;
		}
		if (postorder[n3] != postorder[n3 + n1])
		{
			return false;
		}
		if (preorder[n3] != preorder[n3 + n1])
		{
			return false;
		}
	}
	return true;
}


void build(node * & root, int n1)
{
	if (n1 > n)
	{
		root = NULL;
		return;
	}
	root = new(node);
	build(root->left, n1 * 2);
	root->val = init_val[index++];
	build(root->right, n1 * 2 + 1);
}

int main()
{

	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		cin >> mid;
		init_val.push_back(mid);
	}
	sort(init_val.begin(), init_val.end());//建bst
	node * root;
	build(root, 1);
	node * root_copy;
	copy(root_copy, root);
	order_c(root,1);
	n1 = inorder.size();
	order(root_copy);
	n2 = inorder.size() - n1;
	if (j_eq())
	{
		cout << "相等" << "\n";
	}
	else
	{
		cout << "不相等" << "\n";
	}
	bfs(root);
	cout << "叶子数目：" << leave_count << "\n" << "最大深度：" << maxdeep << "\n";
	for (const int a : inorder)
	{
		cout << a << " ";
	}
	system("pause");
	return 0;
}

/*
输入
10
1 5 4 8 7 9 0 2 6 3
输出
10
1 5 4 8 7 9 0 2 6 3
相等
7
4 9
1 6 8 10
0 2 5

叶子数目：5
最大深度：4
0 1 2 4 5 6 7 8 9 10 0 1 2 4 5 6 7 8 9 10
*/