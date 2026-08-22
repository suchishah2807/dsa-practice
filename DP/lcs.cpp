#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m,vector<int> (n,0));
    // first row
    for(int j=0; j<n; j++){
        dp[0][j] = (text1[0]==text2[j]) ? 1 : (j>0 ? dp[0][j-1] : 0);
    }
    // first col
    for(int i=0; i<m; i++){
        dp[i][0] = (text1[i]==text2[0]) ? 1 : (i>0 ? dp[i-1][0] : 0);
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(text1[i]==text2[j]){
                dp[i][j]=dp[i-1][j-1]+1; //diagonal checking + 1 for same char
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m-1][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}