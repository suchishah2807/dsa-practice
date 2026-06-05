#include <bits/stdc++.h>
using namespace std;
vector<string> res;
bool checkPalindrome(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]) return false;
    }
    return true;
}

vector<string> substring(string s){
    vector<string> ans;
    for(int i=0;i<s.length();i++){
        string substr = s.substr(0,i+1);
        ans.push_back(substr);
    }
    return ans;
}

void helper(vector<vector<string>>& ans, string s, int index){
    if(index==s.length()){
        ans.push_back(res);
        return;
    }
    vector<string> substrs = substring(s.substr(index,s.length()-index));
    for(string sub : substrs){
        if(checkPalindrome(sub)){
            res.push_back(sub);
            helper(ans,s,index+sub.length());
            res.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    helper(ans,s,0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}