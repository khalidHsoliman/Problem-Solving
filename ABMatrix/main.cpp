// Problem Link : https://codeforces.com/problemset/problem/1360/G

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;       cin >> t;
    while(t--)
    {
        int n, m, a, b;     cin >> n >> m >> a >> b;

        if(n * a != m * b)
        {
            cout << "NO" << endl;
            continue;
        }

        int solution[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                solution[i][j] = 0;

/* not working for all test cases

        int startCol = 0;
        int aa = a;
        int bb = b;

        for(int i = 0; i < n; i++)
        {
            for(int j = startCol; j < m; j++)
            {
                solution[i][j] = 1;
                if(--a == 0)
                    break;
            }

            a = aa;
            if(--b == 0)
            {
                startCol += a;
                b = bb;
            }
        }
*/

        int shift = 0;

        for (shift = 1; shift < m; shift++)
            if (shift * n % m == 0)
                break;

        for (int i = 0, dx = 0; i < n; i++, dx += shift)
            for (int j = 0; j < a; j++)
                solution[i][(j + dx) % m] = 1;  // circular shift


        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout << solution[i][j];
            cout << endl;
        }

    }

    return 0;
}
