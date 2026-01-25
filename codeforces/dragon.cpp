#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;

    vector<pair<int,int>> dragons;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;   // x = dragon strength, y = bonus
        dragons.push_back({x, y});
    }

    // sort by dragon strength
    sort(dragons.begin(), dragons.end());

    for (auto d : dragons) {
        int strength = d.first;
        int bonus = d.second;

        if (s > strength) {
            s += bonus;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
