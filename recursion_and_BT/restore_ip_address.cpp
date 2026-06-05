#include <bits/stdc++.h>
using namespace std;

void combinations(string s, int i, int par, string ans, vector<string>& res){
    if(par==4 && i==s.length()){ res.push_back(ans); return; }
    if(par==4 || i==s.length()) return;

    for(int len=1; len<=3; len++){
        if(i+len > s.length()) break;
        string part = s.substr(i, len);
        if(!isvalid(part)) continue;
        string newAns = ans.empty() ? part : ans+"."+part;
        combinations(s, i+len, par+1, newAns, res);
    }
}

bool isvalid(string s){
    if(s.length()>1 && s[0]=='0') return false;  // leading zero
    return stoi(s) <= 255;
}
    vector<string> restoreIpAddresses(string s) {
        vector <string> res;
        combinations(s,0,0,"",res);
        return res;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}