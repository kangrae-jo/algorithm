class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> memo(m, vector<bool> (n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push({i, 0});
        }

        int answer = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto[y, x] = q.front();
                q.pop();

                for (int dir = 0; dir < 3; dir++) {
                    int y_ = y + OFFSET[dir][0];
                    int x_ = x + OFFSET[dir][1];
                    if (isIn(y_, x_, m, n) && grid[y][x] < grid[y_][x_] && !memo[y_][x_]) {
                        q.push({y_, x_});
                        memo[y_][x_] = true;
                    }
                }
            }
            answer++;
        }

        return answer - 1;
    }

private:
    // 가로로 무조건 이동한다.
    const int OFFSET[3][2] = { {1, 1}, {0, 1}, {-1, 1} };

    bool isIn(int y, int x, int m, int n) {
        return 0 <= y && y < m && 0 <= x && x < n;
    }
};
