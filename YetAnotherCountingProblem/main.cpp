// Problem Link : https://codeforces.com/problemset/problem/1342/C

// x has to be bigger than b - assumes b is bigger than a
// x can not be the LCM of a and b and also not LCM+1 >> LCM+(b-1)

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}

long long CountX(long long r, int lcm, int b) {

    long long numberOfLcmBlocks = r / lcm;                    // e.g for a = 3 , b = 4 , lcm = 12 .. numberOfLcmBlocks (r = 100) = 100/12 = 8
    long long highestLcmInRange = numberOfLcmBlocks * lcm;    // highestLcmInRange = 8 * 12 = 96
    long long rangeOfPossibleNumbers = r;   // 1 to r

    if (numberOfLcmBlocks != 0)
    {
        rangeOfPossibleNumbers -= min((long long)b, r - highestLcmInRange + 1); // for the last block because if might not be included completely
        rangeOfPossibleNumbers -= (numberOfLcmBlocks - 1) * b;
    }

    return rangeOfPossibleNumbers - min(r, (long long)(b - 1));                // for the first block
}

int main()
{
    int t;      cin >> t;
    while(t--)
    {
        int a, b, q;    cin >> a >> b >> q;

        if(a > b)   swap(a, b);         // assumes that a is smaller than b
        int lcm = (a * b) / gcd(a, b);

        while(q--)
        {
            long long l, r;   cin >> l >> r;

            if(lcm == b || (r < b))
            {
                cout << 0 << " ";
                continue;
            }

            long long numberOfSolutions = CountX(r, lcm, b);                  // count from 0 to r
            if(l > 1)   numberOfSolutions -= CountX(l - 1, lcm, b);     // count from 0 to l-1 then sub to result count from l to r
            cout << numberOfSolutions << " ";
        }

        cout << endl;

// brute force
/*
        while(q--)
        {
            int numberOfSolutions = 0;

            long long l, r;     cin >> l >> r;
            int x = max((long long) min(a, b), l);

            while(x <= r)
            {
                int modeLHS = (x % a) % b;
                int modeRHS = (x % b) % a;

                if(modeLHS != modeRHS)
                    numberOfSolutions++;

                x++;
            }

            cout << numberOfSolutions << endl;

        }
*/
    }

    return 0;
}
