#include <bits/stdc++.h>
using namespace std;

    bool helper(vector<vector<char>>& board, string& word,
                int row, int col, int index) {

        // found path
        if(index == word.size())
            return true;

        int rows = board.size();
        int cols = board[0].size();

        // invalid position/not found
        if(row < 0 || row >= rows || col < 0 || col >= cols ||
           board[row][col] != word[index])
            return false;

        // mark current as visited
        char temp = board[row][col];
        board[row][col] = '#';

        bool found =
            helper(board, word, row + 1, col, index + 1) ||
            helper(board, word, row - 1, col, index + 1) ||
            helper(board, word, row, col + 1, index + 1) ||
            helper(board, word, row, col - 1, index + 1);

        board[row][col] = temp; // backtracking

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(helper(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}