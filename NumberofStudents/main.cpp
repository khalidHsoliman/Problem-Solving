// Problem Link : https://leetcode.com/contest/weekly-contest-189

#include <bits/stdc++.h>

using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime);

int main()
{
    int t;       cin >> t;
    while(t--)
    {
        vector<int> startTime; vector<int> endTime; int queryTime; int n; int element;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> element;
            startTime.push_back(element);
        }

        for(int i = 0; i < n; i++)
        {
            cin >> element;
            endTime.push_back(element);
        }

        cin >> queryTime;

        cout << startTime[0] << endl << endTime[0] << endl << queryTime;

        int num = busyStudent(startTime, endTime, queryTime);
        cout << num << endl;
    }

    return 0;
}

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime)
{
    int num = 0;
    int n = startTime.size();
    vector< pair <int,int> > vect;

    for(int i = 0; i < n; i++)
    {
        vect.push_back( make_pair(startTime[i],endTime[i]));
    }

    sort(vect.begin(), vect.end());

    if((queryTime < vect[0].first))
        return num;

    for(int i = 0; i < n; i++)
    {
        if((queryTime >= vect[i].first) && (queryTime <= vect[i].second))
            num++;
    }

    return num;
}
