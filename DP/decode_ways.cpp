#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> memo;  // i → number of ways to decode from i

int helper(string s, int i){
    if(i == s.length()) return 1;        // successfully decoded everything
    if(s[i] == '0') return 0;            // invalid, can't start with 0
    if(memo.count(i)) return memo[i];

    int ways = helper(s, i+1);           // take 1 digit

    if(i+1 < s.length() && stoi(s.substr(i,2)) <= 26){
        ways += helper(s, i+2);          // take 2 digits
    }

    return memo[i] = ways;
}

int numDecodings(string s){
    memo.clear();
    return helper(s, 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}