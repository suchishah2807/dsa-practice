#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> memo;
int mincost(vector<int>& cost, int i){
    if(i >= cost.size()) return 0;
    if(memo.count(i)) return memo[i];
    return memo[i] = cost[i] + min(mincost(cost,i+1), mincost(cost,i+2));
}    
int minCostClimbingStairs(vector<int>& cost) {
    return min(mincost(cost,0),mincost(cost,1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}