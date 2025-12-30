#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Rule 1: check rows
        for (auto &v : board) {
            for (auto v1 : v) {
                if (v1 != '.') {
                    if (count(v.begin(), v.end(), v1) != 1) {
                        return false;
                    }
                }
            }
        }

        // Rule 2: check columns
        for (int i = 0; i < 9; i++) {
            vector<char> v2;
            for (auto &v : board) {
                v2.push_back(v[i]);
            }
            for (auto v3 : v2) {
                if (v3 != '.') {
                    if (count(v2.begin(), v2.end(), v3) != 1) {
                        return false;
                    }
                }
            }
        }

        // Rule 3: check 3x3 grids
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                vector<char> grid;
                grid.push_back(board[r][c]);
                grid.push_back(board[r][c+1]);
                grid.push_back(board[r][c+2]);
                grid.push_back(board[r+1][c]);
                grid.push_back(board[r+1][c+1]);
                grid.push_back(board[r+1][c+2]);
                grid.push_back(board[r+2][c]);
                grid.push_back(board[r+2][c+1]);
                grid.push_back(board[r+2][c+2]);

                for (auto nums : grid) {
                    if (nums != '.') {
                        if (count(grid.begin(), grid.end(), nums) != 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};


int main() {
    vector<vector<char>> board(9, vector<char>(9));

    // Input: 9 rows, each with 9 characters (digits or '.')
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    bool result = obj.isValidSudoku(board);

    if (result)
        cout << "true";
    else
        cout << "false";

    return 0;
}