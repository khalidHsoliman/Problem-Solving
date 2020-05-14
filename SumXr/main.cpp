// https://codeforces.com/problemset/problem/627/A

#include <bits/stdc++.h>
using namespace std;

long long countSetBits(long long n);

int main()
{
    long long s, x;
    cin >> s >> x;

    long long tmp = s - x;

    if(tmp%2==1)
    {
        cout << 0;
        return 0;
    }
    tmp /= 2;

    if((tmp & x)!=0)
    {
        cout << 0;
        return 0;
    }

    long long count = countSetBits(x);

    if(tmp!=0)
        cout <<  (1ULL<<count);
    else
        cout << ((1ULL<<count)-2);

    return 0;
}


long long countSetBits(long long n)
{
    long long count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

