// Problem Link : https://codeforces.com/problemset/problem/1367/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;       cin >> t;
    while(t--)
    {
        int n;   cin >> n;
        int a[n];

        int numOfEven  = 0;
        int numOfSwaps = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] % 2 == 0)
                numOfEven++;
        }

        if(numOfEven != ceil((double)n/2))
        {
            cout << -1 << endl;
            continue;
        }


        for(int i = 0; i < n; i+= 2)
            if((a[i] % 2) != (i % 2))
                numOfSwaps++;

        cout << numOfSwaps << endl;
    }

    return 0;
}
