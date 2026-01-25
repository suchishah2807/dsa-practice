#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // prefix sum of original array
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + arr[i];

    // sorted array
    vector<long long> sorted = arr;
    sort(sorted.begin(), sorted.end());

    // prefix sum of sorted array
    vector<long long> pref_sorted(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref_sorted[i + 1] = pref_sorted[i] + sorted[i];

    int q;
    cin >> q;

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            cout << pref[r] - pref[l - 1] << "\n";
        } else {
            cout << pref_sorted[r] - pref_sorted[l - 1] << "\n";
        }
    }
}
