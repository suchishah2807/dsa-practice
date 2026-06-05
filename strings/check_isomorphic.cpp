#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t){
    vector<int> maps(256, -1);  // s char → last seen index
    vector<int> mapt(256, -1);  // t char → last seen index
    
    for(int i=0; i<s.length(); i++){
        if(maps[s[i]] != mapt[t[i]]) return false;  // mapping mismatch
        maps[s[i]] = i;
        mapt[t[i]] = i;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}