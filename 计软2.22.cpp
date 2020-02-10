#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<char> queue;
	int n;
	cin >> n;
	int front = 1, rear = 1;
	for (int n1 = 0; n1 < n; n1++)
	{
		char mid;
		cin >> mid;
		if (mid == 'r')
		{
			int midn;
			cin >> midn;
			for (int n2 = 0; n2 < midn; n2++)
			{
				char midr;
				cin >> midr;
				queue.push_back(midr);
				rear += 1;
			}
			cout <<front << " " << rear<<"\n";
		}
		else
		{
			int midn;
			cin >> midn;
			for (int n2 = 0; n2 < midn; n2++)
			{
				char midr;
				cin >> midr;
				front += 1;
			}
			cout << front << " " << rear << "\n";
		}
	}
	system("pause");
	return 0;
}
/*
ÊäÈë
5
r 5 d e b g h
c 2 d e
r 5 i j k m l
c 1 b
r 5 n o p q r
*/

/*
Êä³ö
5
r 5 d e b g h
1 6
c 2 d e
3 6
r 5 i j k m l
3 11
c 1 b
4 11
r 5 n o p q r
4 16
*/