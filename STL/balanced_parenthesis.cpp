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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    unordered_map<char, int> pairs = {
        {'(', -3},
        {'[', -2},
        {'{', -1},
        {')', 3},
        {']', 2},
        {'}', 1}};

    while (t--)
    {
        string s;
        cin >> s;

        stack<char> st;

        for (char ch : s)
        {
            // opening bracket
            if (pairs[ch] < 0)
            {
                st.push(ch);
            }
            // closing bracket
            else
            {
                if (st.empty())
                {
                    cout << "NO";
                    break;
                }
                char top = st.top();
                st.pop();
                if (pairs[top] + pairs[ch] != 0)
                {
                    cout << "NO";
                    break;
                }
            }
        }
        if (st.empty())
        {
            cout << "YES";
        }
    }
    return 0;
}