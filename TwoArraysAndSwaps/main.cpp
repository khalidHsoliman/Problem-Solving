//https://codeforces.com/problemset/problem/1353/B

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int t;      cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        int a[n], b[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];

            sort(a, a+n);
        sort(b, b+n);

        int maxElementIndex = n - 1;

        for(int i = 0; i < k; i++)
        {
            if(a[i] < b[maxElementIndex - i])
                swap(a[i], b[maxElementIndex - i]);
            else
                break;
        }
        int sum = 0;
        cout << accumulate(a, a+n, sum) << endl;
    }

    return 0;
}
