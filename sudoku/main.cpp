#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; ++i) {
        if (board[i][c] == ch) return false;
        if (board[r][i] == ch) return false;
        if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == ch) return false;
    }
    return true;
}

void backTrack(vector<vector<char>>& board, int i, int j) {
    int m = 9, n = 9;
    if (j == n) {
        backTrack(board, i + 1, 0);
        return;
    }
    if (i == m) {
        return;
    }
    if (board[i][j] != '.') {
        backTrack(board, i, j + 1);
        return;
    }

    for (char ch = '1'; ch <= '9'; ++ch) {
        if (!isValid(board, i, j, ch)) {
            continue;
        }
        board[i][j] = ch;
        backTrack(board, i, j + 1);
        board[i][j] = '.';
    }
}

void solveSudoku(vector<vector<char>>& board) {
    backTrack(board, 0, 0);
}

int main() {
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);

    return 0;
}
