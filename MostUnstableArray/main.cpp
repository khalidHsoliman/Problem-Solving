//https://codeforces.com/problemset/problem/1353/A

#include <iostream>

using namespace std;

int main()
{
    int t;      cin >> t;
    while(t--)
    {
        long long n, m, maxDiff = 0;     cin >> n >> m;
        if(n > 1)
        {
            if(n == 2)
                maxDiff = m;
            else
                maxDiff = 2 * m;
        }

        cout << maxDiff << endl;
    }

    return 0;
}
