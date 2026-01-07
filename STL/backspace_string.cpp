#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <string>
#include <stack>
#include <queue>

using namespace std;
bool backspaceCompare(string s, string t)
{
    vector<char> v1;
    vector<char> v2;
    for (int i = 0; i < s.length(); i++)
    {
        if (v1.size() == 0 && s[i] == '#')
        {
            ;
        }
        else if (s[i] == '#')
        {
            v1.pop_back();
        }
        else
        {
            v1.push_back(s[i]);
        }
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (v2.size() == 0 && t[i] == '#')
        {
            ;
        }
        else if (t[i] == '#')
        {
            v2.pop_back();
        }
        else
        {
            v2.push_back(t[i]);
        }
    }
    if (v1.size() != v2.size())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    cout << backspaceCompare(s, t);

    return 0;
}