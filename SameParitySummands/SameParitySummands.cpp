// SameParitySummands.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://codeforces.com/problemset/problem/1352/B

#include <iostream>

using namespace std; 

int main( )
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int n1 = n - ( k - 1 );
		if (n1 > 0 && n1 % 2 == 1)
		{
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; ++i) cout << "1 ";
			cout << n1 << endl;
			continue;
		}
		int n2 = n - 2 * ( k - 1 );
		if (n2 > 0 && n2 % 2 == 0)
		{
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; ++i) cout << "2 ";
			cout << n2 << endl;
			continue;
		}
		cout << "NO" << endl;
	}
}



