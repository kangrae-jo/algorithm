#include <queue>
#include <vector>

const int WATER = 0;
const int LAND = 1;
const int OFFSET[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
public:
    int N;
    int M;

    int islandPerimeter(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        int sum = 0;
        vector<vector<bool>> visited(N, vector<bool> (M, false));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (grid[y][x] == LAND && !visited[y][x]) sum += getIslandPerimeter(grid, y, x, visited);
            }
        }

        return sum;
    }

private:
    bool isIn(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

    int getIslandPerimeter(vector<vector<int>>& grid, int y, int x, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({y, x});
        visited[y][x] = true;

        int sum = 0;
        while (!q.empty()) {
            auto [curY, curX] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextY = curY + OFFSET[dir][0];
                int nextX = curX + OFFSET[dir][1];
                if (!isIn(nextY, nextX) || grid[nextY][nextX] == WATER) {
                    sum++;
                }
                else if (grid[nextY][nextX] == LAND && !visited[nextY][nextX]) {
                    q.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
            }
        }

        return sum;
    }
};
