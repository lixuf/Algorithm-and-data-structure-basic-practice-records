#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define dj (randlist[use]+d1)%13
string hash1[13];
bool hash2[13];
int randlist[5] = { 3,7,1,12,10 };
int d1;
void combat(string x)
{
	int use = 0;
	while (1)
	{
		if (use > 4)
		{
			use = 0;
		}
		int mid = dj;
		if (hash2[mid] != 1)
		{
			hash1[mid] = x;
			hash2[mid] = 1;
			return ;
		}
		use += 1;
	}
}
int main()
{
	for (int n1 = 0; n1 < 13; n1++)
	{
		hash2[n1] = 0;
	}
	int n;
	cin >> n;
	for (int n1 = 0; n1 < n; n1++)
	{
		string mid;
		cin >> mid;
		int midn = mid[0] - 65;
		if (hash2[midn] == 0)
		{
			hash2[midn] = 1;
			hash1[midn] = mid;
		}
		else
		{
			d1 = midn;
			combat(mid);
		}
	}
	for (int n1=0;n1<13;n1++)
	{
		if (hash2[n1])
		{
			cout << hash1[n1] << " ";
		}
	}
	system("pause");
	return 0;
}


/*
ÊäÈë
10
ICKES BARBER ELYOT KERN FRENCE LOWER BENSDN FONK ERVIN KNOX
Êä³ö
KNOX BARBER BENSDN ELYOT FRENCE ERVIN ICKES KERN LOWER FONK
*/