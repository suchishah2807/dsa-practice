#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, set<string>> m1;

    for (int i = 0; i < n; i++)
    {
        string name;
        int marks;
        cin >> name >> marks;
        m1[marks].insert(name);
    }

    // Print in decreasing order of marks
    for (auto it = m1.rbegin(); it != m1.rend(); it++)
    {
        for (const string &name : it->second)
        {
            cout << name << " " << it->first << "\n";
        }
    }
}
