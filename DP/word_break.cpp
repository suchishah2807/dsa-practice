#include <bits/stdc++.h>
using namespace std;

bool helper(string s, int start, unordered_set<string>& wordSet, unordered_map<int,bool>& memo){
    if(start == s.length()) return true;
    if(memo.count(start)) return memo[start];

    for(int len = 1; len <= s.length()-start; len++){
        string word = s.substr(start, len);
        if(wordSet.count(word) && helper(s, start+len, wordSet, memo)){
            return memo[start] = true;
        }
    }
    return memo[start] = false;
}

bool wordBreak(string s, vector<string>& wordDict){
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    unordered_map<int,bool> memo;
    return helper(s, 0, wordSet, memo);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}