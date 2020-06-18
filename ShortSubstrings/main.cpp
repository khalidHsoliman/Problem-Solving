// Problem Link : https://codeforces.com/problemset/problem/1367/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;       cin >> t;
    while(t--)
    {
        string b;  cin >> b;
        string a = " ";
        a = b[0];
        for(int i = 1; i < b.length() - 1; i+=2)
            a += b[i];

        a += b[b.length() - 1];

        cout << a << endl;
    }

    return 0;
}
