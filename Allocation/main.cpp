// Problem Link : Round A 2020 - Kick Start 2020

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;       cin >> t;
    int caseNumber = 1;

    while(t--)
    {
        int n, b;   cin >> n >> b;
        int a[n];
        int suma[n];
        int numOfHouses;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        suma[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            suma[i] = suma[i-1] + a[i];
        }

        for(int i = 0; i < n; i++)
        {
            if(b < suma[i])
            {
                numOfHouses = i;
                break;
            }
        }

        cout << "Case #" << caseNumber << ": " << numOfHouses << endl;
        caseNumber++;
    }

    return 0;
}
