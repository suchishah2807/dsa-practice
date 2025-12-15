// Problem: Reverse Array
// Approach: Use STL reverse()
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    reverse(arr.begin(), arr.end());

    for(int x : arr) cout << x << " ";
    return 0;
}
