// Problem Link : https://codeforces.com/problemset/problem/1334/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;       cin >> t;
    while(t--)
    {
        int n, p, c;  cin >> n;
        int previousP = 0; int previousC = 0;
        string couldExist = "YES";
//  brute force but sufficient
        for(int i = 0; i < n; i++)
        {
            cin >> p >> c;
            if(p < previousP || c < previousC || c > p || ((p - previousP) < (c - previousC)))
            {
                couldExist = "NO";
            }

            previousP = p; previousC = c;
        }

        cout << couldExist << endl;
    }

    return 0;


}
