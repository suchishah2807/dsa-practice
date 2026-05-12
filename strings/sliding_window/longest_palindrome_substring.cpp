#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int n=s.length();
    int maxlength=0;
    int start=0;
    for(int i=0;i<n;i++){
        // odd
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxlength) {
                maxlength = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
        // even
        int left=i,right=i+1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxlength) {
                maxlength = right - left + 1;
                start = left;
            }
        left--;
        right++;
        }
    }
    cout<<s.substr(start,maxlength);
    return 0;
}