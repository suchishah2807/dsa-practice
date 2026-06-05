#include <bits/stdc++.h>
using namespace std;

void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans, vector<bool>& coln, vector<bool>& nor_diag, vector<bool>& rev_diag){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){ // placing queen in each column for each row
            if(!coln[col] && !nor_diag[row+col] && !rev_diag[row-col+n-1]){ // making sure that particular column, diag, rev diag are not occupied
                // place queen
                board[row][col] = 'Q';
                coln[col] = true;
                nor_diag[row+col] = true;
                rev_diag[row-col+n-1] = true;

                solve(row+1, n, board, ans, coln, nor_diag, rev_diag); // placement of next row

                // backtrack
                board[row][col] = '.';
                coln[col] = false;
                nor_diag[row+col] = false;
                rev_diag[row-col+n-1] = false;
            }
        }
    }

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));  // n strings of n dots
    vector<bool> coln(n, false);
    vector<bool> nor_diag(2*n-1, false);
    vector<bool> rev_diag(2*n-1, false);
    solve(0, n, board, ans, coln, nor_diag, rev_diag);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<string>> result = solveNQueens(4);
    for(auto row : result){
        for(auto column : row){
            cout<<column<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}