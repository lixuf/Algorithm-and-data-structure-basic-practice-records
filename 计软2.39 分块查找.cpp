#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct block
{
	int boock_val;
	vector<int> stu_id;
};
const int block_num = 4;
int main()
{
	int n;
	cin >> n;
	vector<block *> sum;
	int start = 97200;
	for (int n1 = 0; n1 < block_num; n1++)
	{
		block * mid = new (block);
		mid->boock_val = start;
		sum.push_back(mid);
		start += 100;
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		cin >> mid;
		if (mid > 97100 && mid <= 97200)
		{
			sum[0]->stu_id.push_back(mid);
			continue;
		}
		else if (mid > 97200 && mid <= 97300)
		{
			sum[1]->stu_id.push_back(mid);
			continue;
		}
		else if (mid > 97300 && mid <= 97400)
		{
			sum[2]->stu_id.push_back(mid);
			continue;
		}
		else if (mid > 97500 && mid <= 97600)
		{
			sum[3]->stu_id.push_back(mid);
			continue;
		}
		
	}
	for (int n1 = 0; n1 < block_num; n1++)
	{
		sort(sum[n1]->stu_id.begin(), sum[n1]->stu_id.end());
		cout << sum[n1]->boock_val << '\n';
		for (int n2 = 0; n2 < sum[n1]->stu_id.size(); n2++)
		{
			cout << sum[n1]->stu_id[n2] << " ";
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}
/*
ÊäÈë
17
97438 97102 97528 97136 97338 97250 97407 97239 97227 97517 97321 97421 97451 97241 97118 97543 97309
Êä³ö
97200
97102 97118 97136
97300
97227 97239 97241 97250
97400
97309 97321 97338
97500
97517 97528 97543
*/