#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& board, int i, int j) {
    int m = board.size(), n = board[0].size();
    if (i < 0 || i > m || j < 0 || j > n) {
        return;
    }
    if (board[i][j] != 'O') {
        return;
    } else {
        board[i][j] = '#';
    }
    dfs(board, i + 1, j);
    dfs(board, i, j + 1);
    dfs(board, i - 1, j);
    dfs(board, i, j - 1);
}

void solve(vector<vector<char>>& board) {
    if (board.size() == 0) return;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
        dfs(board, i, 0);
        dfs(board, i, n - 1);
    }
    for (int j = 0; j < n; ++j) {
        dfs(board, 0, j);
        dfs(board, m - 1, j);
    }

    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
