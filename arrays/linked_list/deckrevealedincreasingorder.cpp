#include <bits/stdc++.h>
using namespace std;
vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(),deck.end());
    queue <int> q;
    int n = deck.size();
    for(int i=n-1;i>-1;i--){
        if(i==n-1) q.push(deck[i]);
        else
        {int top = q.front();
        q.pop();
        q.push(top);
        q.push(deck[i]);}

    }
    vector <int> ans;
    while(!q.empty()){
    ans.push_back(q.front());
    q.pop();
}
reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
	// your code goes here
    vector <int> deck = {17,13,11,2,3,5,7};
    vector <int> answer = deckRevealedIncreasing(deck);
    for(int ans: answer){
        cout<<ans<<" ";
}
}
