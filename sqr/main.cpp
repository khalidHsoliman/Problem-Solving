// https://codeforces.com/problemset/problem/1351/B

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;


    cin >> t;
    while(t--)
    {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;

        bool rec = false;
        int maxNum = 0, area = 0;
        if(std::max(a1, b1) == std::max(a2, b2))
        {
        maxNum = std::max(max(a1,a2), max(b1,b2));
        area = (a1 * b1) + (a2 * b2);
        if(area%maxNum == 0 && area/maxNum == maxNum)
            rec = true;
        }

// brute force
/*
        if(a1 == a2 || a1 == b2 || b1 == a2 || b1 == b2)
        {
            if(a1 == a2)
            {
                if(b1 + b2 == a1)
                    rec = true;
            }

            else if (a1 == b2)
            {
                if(b1 + a2 == a1)
                    rec = true;
            }

            else if (b1 == a2)
            {
                if(a1 + b2 == b1)
                    rec = true;
            }

            else if (b1 == b2)
            {
                if(a1 + a2 == b1)
                    rec == true;
            }

        }
*/
        if(rec) cout << "YES" << endl;
        else    cout << "NO"  << endl;
    }

    return 0;
}
