// https://leetcode.com/contest/weekly-contest-189

#include <bits/stdc++.h>

using namespace std;

bool compare(string &s1,string &s2){return s1.size() <= s2.size();}
string arrangeWords(string text);


int main()
{
    cout << arrangeWords("Hi i am Khalid")<< endl;
    return 0;
}

string arrangeWords(string text)
{
    vector<string> mystring;

    istringstream iss(text);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(mystring));

    sort(mystring.begin(), mystring.end(), compare);

    for(int i = 0; i < mystring.size(); i++)
    {
        if(i % 2 == 1)
            mystring.insert(mystring.begin() + i, " ");
    }

    string text2;
    stringstream res;
    copy(mystring.begin(), mystring.end(), ostream_iterator<string>(res, ""));
    text2 = res.str();
    text2[0] = toupper(text2[0]);
    for(int i = 1; i < text2.size(); i++)
        text2[i] = tolower(text2[i]);
    return text2;

}

