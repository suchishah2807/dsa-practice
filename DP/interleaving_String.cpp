#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if(s3.length()!=s1.length()+s2.length()){
        return false;
    }
    int n = s1.length();
    int m = s2.length();
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    dp[0][0]=true;
    for(int i=1;i<n+1;i++){
        dp[0][i]=dp[0][i-1] && s1[i-1]==s3[i-1];
    }
    for(int i=1;i<m+1;i++){
        dp[i][0]=dp[i-1][0] && s2[i-1]==s3[i-1];
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            dp[i][j]=((dp[i-1][j] && s2[i-1]==s3[i+j-1]) || (dp[i][j-1] && s1[j-1]==s3[i+j-1]));
        }
    }
    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}