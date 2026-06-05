#include <bits/stdc++.h>
using namespace std;
// leetcode 168
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber > 0){
            int ch = columnNumber % 26;
            if(ch == 0){
                s += 'Z';
                columnNumber = columnNumber/26 - 1;
            } else {
                s += (char)('A' + ch - 1);
                columnNumber = columnNumber/26;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}