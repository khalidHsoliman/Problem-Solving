//https://codeforces.com/problemset/problem/1353/C

#include <iostream>

using namespace std;

int main()
{
    int t;      cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        long long numOfCellsToBeMoved = (long long)n * n - 1;

        int costOfMoving = 1;
        long long NumOfCellsPerLevel = 8;

        long long minNumOfMoves = 0;


        while(numOfCellsToBeMoved > 0)
        {
            minNumOfMoves += costOfMoving * NumOfCellsPerLevel;

            numOfCellsToBeMoved -= NumOfCellsPerLevel;
            NumOfCellsPerLevel += 8;
            costOfMoving++;
        }

        cout << minNumOfMoves << endl;
    }

    return 0;
}
