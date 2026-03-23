#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int maxProfit=0;
        for(auto& price : prices){
            if (price<buy){
                buy=price;
            }
            else{
                maxProfit=max(maxProfit,price-buy);
            }
        }
        return maxProfit;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin>>n;
    vector <int> prices(n);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        prices[i]=num;
    }
    int profit=sol.maxProfit(prices);
    cout<<profit;

    return 0;
}