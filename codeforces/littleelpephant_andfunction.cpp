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
void f(string s, int n)
{
    s += to_string(n);
    if (n > 1)
    {
        s += " ";
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                s += to_string(i);
            }
            else{
            s += to_string(i) + " ";
            }
        }
    }
    cout << s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    f("", n);

    return 0;
}