class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (y == 0 || x == 0) {
                    grid[y][x] = 1;
                    continue;
                }

                grid[y][x] = grid[y - 1][x] + grid[y][x - 1];
            }
        }

        return grid[m - 1][n - 1];
    }
};
