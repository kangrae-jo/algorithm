#include <vector>
#include <queue>

const char LAND = '1';
const char WATER = '0';
const int OFFSET[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    int N, M;

    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();

        vector<vector<bool>> visited(N, vector<bool> (M, false));
        int sum = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (grid[y][x] == LAND && !visited[y][x]) {
                    bfs(grid, y, x, visited);
                    sum++;
                }
            }
        }
        return sum;
    }

private:
    bool isIn(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < M;
    }

    void bfs(vector<vector<char>>& grid, int sY, int sX, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({sY, sX});
        visited[sY][sX] = true;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0];
                int x_ = x + OFFSET[dir][1];

                if (isIn(y_, x_) && grid[y_][x_] == LAND && !visited[y_][x_]) {
                    q.push({y_, x_});
                    visited[y_][x_] = true;
                }
            }
        }
    }
};
