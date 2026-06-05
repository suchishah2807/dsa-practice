#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& grid){
    if(row == 9) return true;
    if(col == 9) return solve(board, row+1, 0, rows, cols, grid);
    if(board[row][col] != '.') return solve(board, row, col+1, rows, cols, grid);

    for(int i = 1; i <= 9; i++){
        if(!rows[row][i] && !cols[col][i] && !grid[(row/3)*3 + (col/3)][i]){
            board[row][col] = '0' + i;
            rows[row][i] = cols[col][i] = grid[(row/3)*3+(col/3)][i] = true;
            if(solve(board, row, col+1, rows, cols, grid)) return true;
            board[row][col] = '.';
            rows[row][i] = cols[col][i] = grid[(row/3)*3+(col/3)][i] = false;
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board){
    vector<vector<bool>> rows(9, vector<bool>(10, false));
    vector<vector<bool>> cols(9, vector<bool>(10, false));
    vector<vector<bool>> grid(9, vector<bool>(10, false));
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if(board[r][c] != '.'){
                int num = board[r][c] - '0';
                rows[r][num] = cols[c][num] = grid[(r/3)*3+(c/3)][num] = true;
            }
        }
    }
    solve(board, 0, 0, rows, cols, grid);
}

void printBoard(vector<vector<char>>& board){
    for(int r = 0; r < 9; r++){
        if(r % 3 == 0 && r != 0) cout << "-------+--------+-------\n";
        for(int c = 0; c < 9; c++){
            if(c % 3 == 0 && c != 0) cout << " | ";
            cout << board[r][c] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);
    printBoard(board);
    return 0;
}