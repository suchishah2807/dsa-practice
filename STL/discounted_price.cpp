#include <bits/stdc++.h>
using namespace std;
vector<int> finalPrices(vector<int>& prices) {
    stack <pair<int,int>> st;
    int n = prices.size();
    vector<int> answers(n);
    for(int i=n-1;i>-1;i--){
        while(!st.empty() && st.top().first > prices[i]){
            st.pop();
        }
        if(st.empty()) {
            st.push({prices[i],prices[i]});
            answers[i]=st.top().second;
            continue;
        }
        st.push({prices[i],prices[i]-st.top().first});
        answers[i]=st.top().second;
    }
    return answers;
}
int main() {
	// your code goes here
    vector <int> prices = {10,1,1,6};
    vector <int> ans = finalPrices(prices);
    for(int discount : ans){
        cout<<discount<<" ";
    }
}
