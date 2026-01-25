#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n - 1;
    int sereja = 0, dima = 0;
    int turn = 0;

    while (l <= r) {
        int pick;
        if (a[l] > a[r]) {
            pick = a[l];
            l++;
        } else {
            pick = a[r];
            r--;
        }

        if (turn % 2 == 0)
            sereja += pick;
        else
            dima += pick;

        turn++;
    }

    cout << sereja << " " << dima << endl;
}
