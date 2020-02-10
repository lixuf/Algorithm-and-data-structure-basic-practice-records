#include<vector>
#include<iostream>
using namespace std;
const int m = 10;//数组长度
int main()
{
	vector<int> a(m, 0);
	int top1 = -1, top2 = a.size();
	while (top1 != top2 - 1)
	{
		int mid;
		cin >> mid;
		if (mid % 2 == 1)
		{
			a[top2] = mid;
			top2--;
		}
		else
		{
			a[top1] = mid;
			top1++;
		}
	}
	return 0;
}
