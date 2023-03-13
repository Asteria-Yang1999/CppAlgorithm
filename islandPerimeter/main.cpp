#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp = 0;
            if (grid[i][j] == 0) continue;
            else {
                if (i - 1 >= 0 && grid[i - 1][j] == 1) tmp++;
                if (j - 1 >= 0 && grid[i][j - 1] == 1) tmp++;
                if (j + 1 < n && grid[i][j + 1] == 1) tmp++;
                if (i + 1 < m && grid[i + 1][j] == 1) tmp++;
            }
            res += (4 - tmp);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> grid = {{0, 1, 0, 0},
                                {1, 1, 1, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0}};
    cout << islandPerimeter(grid);
    return 0;
}
