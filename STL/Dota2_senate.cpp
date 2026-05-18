#include <bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate) {
    queue <int> R;
    queue <int> D;
    for(int i=0;i<senate.length();i++){
        if(senate[i]=='R') R.push(i);
        else D.push(i);
    }
    while(!R.empty() && !D.empty()){
        if(R.front()<D.front()){
            D.pop();
            R.push(R.front()+senate.length());
            R.pop();
        }
        else{
            R.pop();
            D.push(D.front()+senate.length());
            D.pop();
        }
    }
    if(!R.empty()) return "Radiant";
    if(!D.empty()) return "Dire";
    return "0";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string senate = "RDD";
    string ans = predictPartyVictory(senate);
    cout<<ans;
    

    return 0;
}