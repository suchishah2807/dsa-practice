#include <bits/stdc++.h>
using namespace std;
// leetcode 171
int titleToNumber(string columnTitle) {
        int ans=0;
        for(int i=0;i<columnTitle.length();i++){
            ans=ans*26;
            int num = columnTitle[i]-'A' + 1;
            ans+=num;
        }
        return ans;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}