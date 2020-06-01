// Problem Link : https://codeforces.com/problemset/problem/958/C1

#include <bits/stdc++.h>

using namespace std;

long long sumArray(int j, int n, int arr[])
{
    long long sum = 0;
    for(int i = j; i < n; i++)
        sum += arr[i];

    return sum;
}

int main()
{
    int n, p;       cin >> n >> p;
    int arr[n], modarr[n];
    int sum = 0;
    int cutOffIndex = -1;

    cin >> arr[0];
    modarr[0] = arr[0] % p;

    for(int i = 1; i < n; i++)
    {
        cin >> arr[i];
        modarr[i] = ((arr[i] % p) + modarr[i - 1]) % p;
        if((modarr[i] <= modarr[i-1]) && (cutOffIndex == -1))
        {
            cutOffIndex = i - 1;
        }
    }

    if(cutOffIndex != -1)
        sum = modarr[cutOffIndex] + (sumArray(cutOffIndex + 1, n, arr) % p);
    else
        sum = sumArray(0, n, arr) % p;

    cout << sum << endl;
    return 0;
}
