#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<int> init{ 4,6,2,3,1,9,7,0,5,8,10,54,24,55,21 };
	vector<int>::iterator itr = init.begin();
	while (itr != init.end()-1)
	{
		if (*itr >= *(itr + 1))
		{
			int mid = *itr;
			*itr = *(itr + 1);
			*(itr + 1) = mid;
			if (itr != init.begin())
			{
				itr--;
			}
		}
		else
		{
			itr++;
		}
	}
	for (auto a : init)
	{
		cout << a << ' ';
	}
	system("pause");
	return 0;
}