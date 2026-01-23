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
    vector<string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    stack<int> st1; // pushing,popping,top for all integers
    stack<int> st2; // stack which holds min number so far

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "push")
        {
            int x;
            cin >> x;
            if (st2.empty())
            {
                st2.push(x);
            }
            else if (st2.top() >= x)
            {
                st2.push(x);
            }
            st1.push(x);
        }
        else if (v[i] == "pop")
        {

            if (st1.top() == st2.top())
            {
                st2.pop();
            }
            st1.pop();
        }
        else if (v[i] == "top")
        {
            cout << st1.top() << endl;
        }
        else if (v[i] == "GetMin")
        {
            cout << st2.top() << endl;
        }
    }

    return 0;
}