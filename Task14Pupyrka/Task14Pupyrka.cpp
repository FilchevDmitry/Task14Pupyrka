#include <iostream>
using namespace std;
void initialization(bool pup[][12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			pup[i][j] = true;
		}
	}
}
bool print(bool pup[][12])
{
	int col = 0;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{	
			pup[i][j]==1? cout << "O": cout << "X";
			cout << " ";
			if (pup[i][j] == false)
				++col;
		}
		cout << endl;
	}
	cout << endl;
	if (col < 144)
	{
		col = 0;
		return true;
	}
	else
		return false;
}
void burst(bool pup[][12], int k,int l, int n, int m)
{
	for (int i = k; i <=n ; i++)
	{
		for (int j = l; j <=m; j++)
		{	
			if (pup[i][j] == true)
			{
				pup[i][j] = false;
				cout << "Pop!" << endl;
			}
			else
				cout << "Already burst!" << endl;
		}
	}
}
bool checking(int k, int l, int n, int m)
{
	if (k < 1 || k>12 || l < 1 || l>12 || n < 1 || n>12 || m < 1 || m>12)
		return false;
	else
		return true;
}
int main()
{
	bool num = true;
	int k = 0, l = 0, n = 0, m = 0;
	bool pup[12][12];
	initialization(pup);
	while (print(pup))
	{	
		while (num) 
		{
			cout << "Enter the initial coordinates (1-12)\n";
			cin >> k >> l;
			cout << "Enter the end coordinates (1-12)\n";
			cin >> n >> m;
			if (!checking(k,l,n,m))
				cout << "Incorrect number input";
			else
				num = false;
		}
		k--;
		l--;
		n--;
		m--;
		burst(pup, k, l, n, m);
		num = true;
	}
	cout << "That is ALL !!!!\n";
}
