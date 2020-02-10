#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<int> init{ 4,6,2,3,1,9,7,0,5,8,10,54,24,55,21 };
	vector<int>::iterator itr,itr3;
	
	auto itr2 = init.end() - 1;
	while (itr2!=init.begin())
	{
		itr = init.begin();
		while (itr != itr2)
		{
			if (*itr >= *(itr + 1))
			{
				int mid = *itr;
				*itr = *(itr + 1);
				*(itr + 1) = mid;
				itr3 = itr;
			}
			itr++;
		}
		itr2=itr3;
		
	}
	for (auto a : init)
	{
		cout << a << ' ';

	}
	system("pause");
	return 0;
}