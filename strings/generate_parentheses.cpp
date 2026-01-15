#include <iostream>
#include <vector>
using namespace std;

void generate(string s, int open, int close, vector<string> &ans)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(s);
        return;
    }

    if (open > 0)
    {
        generate(s + "(", open - 1, close, ans);
    }

    if (close > open)
    {
        generate(s + ")", open, close - 1, ans);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> ans;
    generate("", 3, 3, ans);

    for (auto &x : ans)
        cout << x << "\n";

    return 0;
}
