#include <bits/stdc++.h>
using namespace std;
//leetcode 17

unordered_map<char, string> nums = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };

void combinations(vector<string>& ans,string digits, int index){
    if(index<0){
        ans.push_back("");
        return;
    }
    string s = nums[digits[index]];
    combinations(ans, digits, index-1);
    vector<string> newAns;
    for(string res : ans){
        for(int i=0;i<s.length();i++){
            string new_s = res+s[i];
            newAns.push_back(new_s);
        }
    }
    ans=newAns;
}

vector<string> letterCombinations(string digits) {
    if(digits.length()==0) return {};
vector <string> ans;
combinations(ans, digits, digits.length()-1);
return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <string> ans = letterCombinations("234");
    for(string ds : ans){
        cout<<ds<<" ";
    }
    

    return 0;
}