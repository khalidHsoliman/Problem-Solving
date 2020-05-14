//https://codeforces.com/problemset/problem/1342/A

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int t = 0;          cin >> t;

    long long x = 0, y = 0, a = 0, b = 0;

    while(t--)
    {
        cin >> x >> y >> a >> b;
        long long money = 0;

        long long diff = abs(x - y);
        long long mNum = min(x , y);
        double abRatio = (double)b/a;
        if(abRatio > 2)
            money = (x + y) * a;
        else
            money = mNum * b + diff * a;

// brute force
/*
        while (x > 0 || y > 0)
        {
            if(x > 0 && y > 0)
            {
                money += b;
                x--;
                y--;
            }
            else
            {
                money += a;
                if(x > 0)
                    x--;
                else
                    y--;
            }
        }
*/
        cout << money << endl;
    }

    return 0;
}
