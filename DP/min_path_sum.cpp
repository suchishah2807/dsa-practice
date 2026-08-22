#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> minsum(m,vector<int>(n,0));
    minsum[0][0]=grid[0][0];
    for(int i=1;i<n;i++){
        minsum[0][i]=minsum[0][i-1]+grid[0][i];
    }
    for(int i=1;i<m;i++){
        minsum[i][0]=minsum[i-1][0]+grid[i][0];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            int path = min(minsum[i][j-1],minsum[i-1][j]);
            minsum[i][j] = path + grid[i][j];
        }
    }
    return minsum[m-1][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}