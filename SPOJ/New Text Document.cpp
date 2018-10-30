#include <iostream>
#include <string>
#include <map>
#include <algorithm>
 
using namespace std;
 
bool is_palindrom(string s)
{
    int len = s.length();
    int j;
    if (len % 2 == 0) j = len / 2;
    else j = len / 2 + 1;
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[j++]) return false;
    }
    return true;
}
 
int degree(string s, map<string, int> &degreetb)
{
    int len = s.length();
    if (is_palindrom(s))
    {
        string temp = s.substr(0, len / 2);
        if (degreetb[temp] != 0)
        {
            degreetb[s] = 1 + degreetb[temp];
            return degreetb[s];
        }
        else return 0;
    }
    else return 0;
}
 
int main()
{
    string s;
    cin >> s;
    if (s == "")
    {
        cout << "0" << endl;
        return 0;
    }
 
    map<string, int> degreetb;
    string temp;
    temp += s[0];
    degreetb[temp] = 1;
    int sum = 1;
    int len = s.length();
    for (int i = 1; i < len; i++)
    {
        temp += s[i];
        sum += degree(temp, degreetb);
    }
    cout << sum << endl;
 
    return 0;
}