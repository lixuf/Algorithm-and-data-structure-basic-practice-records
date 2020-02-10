#include<iostream>
#include<vector>
using namespace std;
vector<int>biao;
vector<int> x;
int n;
void out()
{
	for (const int & a : x)
	{
		cout << a << " ";
	}
	cout << "\n";
}
void insert()
{
	x = biao;
	for (int n1 = 1; n1 < n; n1++)
	{
		int mid = n1;
		int temp = x[n1];
		while (mid > 0 && x[mid - 1] > temp)
		{
			x[mid] = x[mid - 1];
			mid--;
		}
		x[mid] = temp;
		out();
	}
}
void simple()
{
	x = biao;
	for (int n1 = 0; n1 < n; n1++)
	{
		int k=n1;
		for (int n2 = n1+1; n2 < n; n2++)
		{
			if (x[n2] <x[k])
			{
				k = n2;
			}
		}
		int mid = x[k];
		x[k] = x[n1];
		x[n1] = mid;
		out();
	}
}
void downadjust(int low, int high)
{
	int i = low, j = low * 2;
	while (j < high)
	{
		if (j + 1 < high&&x[j + 1] > x[j])
		{
			j = j + 1;
		}
		if (x[j] > x[i])
		{
			int temp = x[j];
			x[j] = x[i];
			x[i] = temp;
			i = j;
			j = i * 2;
		}
		else
		{
			break;
		}
	}
}
void creatheap()
{
	for (int n1 = n / 2; n1 >= 0; n1--)
	{
		downadjust(n1, n);
	}
	out();
}
void heap()
{
	x = biao;
	creatheap();
	for (int n1 = n - 1; n1 > 0; n1--)
	{
		int temp = x[n1];
		x[n1] = x[0];
		x[0] = temp;
		downadjust(0, n1);
		out();
	}
}
void bob()
{
	x = biao;
	int k = n - 1;
	for (int n1 = n - 1; n1 > 0;)
	{
		int mid = 0;
		while (mid < n1)
		{
			if (x[mid] > x[mid + 1])
			{
				int temp = x[mid];
				x[mid] = x[mid + 1];
				x[mid + 1] = temp;
				k = mid;
			}
			mid += 1;
		}
		if (n1 - 1 < k)
		{
			n1 = n1 - 1;
		}
		else
		{
			n1 = k;
		}
		out();
	}
}
int part(int left, int right)
{
	int mid = x[left];
	while (left < right)
	{
		while (left<right&&x[right]>mid)
		{
			right--;
		}
		x[left] = x[right];
		while (left < right&&x[left] <= mid)
		{
			left++;
		}
		x[right] = x[left];
	}
	x[left] = mid;
	return left;
}
void quicksort(int left, int right)
{
	if (left < right)
	{
		int pos = part(left, right);
		quicksort(left, pos-1);
		quicksort(pos+1, right);
	}
	out();
}
void quick()
{
	x = biao;
	quicksort(0, n - 1);
	out();
}
int main()
{
	cin >> n;
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		cin >> mid;
		biao.push_back(mid);
	}
	cout << "��������\n";
	insert();
	cout << "������\n";
	simple();
	cout << "������\n";
	heap();
	cout << "��������\n";
	bob();
	cout << "����\n";
	quick();
	system("pause");
	return 0;
}

/*
����
12
41 62 13 84 35 96 57 39 79 61 15 83
���
��������
41 62 13 84 35 96 57 39 79 61 15 83
13 41 62 84 35 96 57 39 79 61 15 83
13 41 62 84 35 96 57 39 79 61 15 83
13 35 41 62 84 96 57 39 79 61 15 83
13 35 41 62 84 96 57 39 79 61 15 83
13 35 41 57 62 84 96 39 79 61 15 83
13 35 39 41 57 62 84 96 79 61 15 83
13 35 39 41 57 62 79 84 96 61 15 83
13 35 39 41 57 61 62 79 84 96 15 83
13 15 35 39 41 57 61 62 79 84 96 83
13 15 35 39 41 57 61 62 79 83 84 96
������
13 62 41 84 35 96 57 39 79 61 15 83
13 15 41 84 35 96 57 39 79 61 62 83
13 15 35 84 41 96 57 39 79 61 62 83
13 15 35 39 41 96 57 84 79 61 62 83
13 15 35 39 41 96 57 84 79 61 62 83
13 15 35 39 41 57 96 84 79 61 62 83
13 15 35 39 41 57 61 84 79 96 62 83
13 15 35 39 41 57 61 62 79 96 84 83
13 15 35 39 41 57 61 62 79 96 84 83
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
������
96 84 83 57 79 62 41 39 35 61 15 13
84 83 79 57 61 62 41 39 35 13 15 96
83 79 62 57 61 15 41 39 35 13 84 96
79 62 61 57 35 15 41 39 13 83 84 96
62 61 35 57 13 15 41 39 79 83 84 96
61 57 35 41 13 15 39 62 79 83 84 96
57 41 35 39 13 15 61 62 79 83 84 96
41 39 35 15 13 57 61 62 79 83 84 96
39 35 13 15 41 57 61 62 79 83 84 96
35 15 13 39 41 57 61 62 79 83 84 96
15 13 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
��������
41 13 62 35 84 57 39 79 61 15 83 96
13 41 35 62 57 39 79 61 15 83 84 96
13 35 41 57 39 62 61 15 79 83 84 96
13 35 41 39 57 61 15 62 79 83 84 96
13 35 39 41 57 15 61 62 79 83 84 96
13 35 39 41 15 57 61 62 79 83 84 96
13 35 39 15 41 57 61 62 79 83 84 96
13 35 15 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
����
13 15 39 35 41 96 57 84 79 61 62 83
13 15 35 39 41 96 57 84 79 61 62 83
13 15 35 39 41 96 57 84 79 61 62 83
13 15 35 39 41 96 57 84 79 61 62 83
13 15 35 39 41 96 57 84 79 61 62 83
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
13 15 35 39 41 57 61 62 79 83 84 96
*/