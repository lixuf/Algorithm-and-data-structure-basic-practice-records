#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;
map<char, int> level;
string in;//**变为~
int n = 0;

bool slt(char a, char b)
{
	return level[a] > level[b];
}

int compute()
{
	stack<int> ns;
	stack<char> os;//os运算符 ns操作数
	os.push(';');
	for (int n1 = n; n1 < in.size(); n1++)
	{
		if (in[n1] >= 48 && in[n1] <= 57)
		{
			ns.push(in[n1] - 48);
		}
		else
		{
			if (in[n1] == '(')
			{
				n = n1 + 1;
				ns.push(compute());
				n1 = n;
				continue;
			}
			if (in[n1] == ')'&&os.top()==';')
			{
				n = n1 + 1;
				while (os.top() != ';')
				{
					int mid1 = ns.top();
					ns.pop();
					int mid2 = ns.top();
					ns.pop();
					char mid3 = os.top();
					os.pop();
					switch (mid3)
					{
					case ';':break;
					case'+':ns.push(mid2 + mid1); break;
					case'-':ns.push(mid2 - mid1); break;
					case'*':ns.push(mid2 * mid1); break;
					case'/':ns.push(mid2 / mid1); break;
					case'`':ns.push(pow(mid2, mid1)); break;
					}
				}
				return ns.top();

			}
			if (slt(in[n1], os.top()))
			{
				os.push(in[n1]);
			}
			else
			{
				int mid1 = ns.top();
				ns.pop();
				int mid2 = ns.top();
				ns.pop();
				char mid3 = os.top();
				os.pop();
				switch (mid3)
				{
				case ';':break;
				case'+':ns.push(mid2 + mid1); break;
				case'-':ns.push(mid2 - mid1); break;
				case'*':ns.push(mid2 * mid1); break;
				case'/':ns.push(mid2 / mid1); break;
				case'`':ns.push(pow(mid2, mid1)); break;
				}
				n1 -= 1;
			}
		}
	}
	while (os.top() != ';')
	{
		int mid1 = ns.top();
		ns.pop();
		int mid2 = ns.top();
		ns.pop();
		char mid3 = os.top();
		os.pop();
		switch (mid3)
		{
		case ';':break;
		case'+':ns.push(mid2 + mid1); break;
		case'-':ns.push(mid2 - mid1); break;
		case'*':ns.push(mid2 * mid1); break;
		case'/':ns.push(mid2 / mid1); break;
		case'`':ns.push(pow(mid2, mid1)); break;
		}
	}
	return ns.top();
}

int main()
{
	
	level[')'] = 0;
	level[';'] = 0;
	level['+'] = 1;
	level['-'] = 1;
	level['*'] = 2;
	level['/'] = 2;
	level['`'] = 3;
	cin >> in;
	cout<<compute();
	system("pause");
}
/*
输入
A*(B-D)/D+C`(E*F)
5*(3-4)/2+2`(3*2)
输出
62
*/