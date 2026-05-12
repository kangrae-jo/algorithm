#include <vector>
#include <queue>

using namespace std;

const int EMPTY = 0;
const int ORANGE = 1;
const int ROTTEN = 2;
const int OFFSET[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
public:
    int N, M;

    int orangesRotting(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        int minutes = bfs(grid);
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (grid[y][x] == ORANGE) {
                    return -1;
                }
            }
        }

        return minutes == 0 ? minutes : minutes - 1;
    }

private:
    bool isIn(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < M;
    }

    int bfs(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (grid[y][x] == ROTTEN) q.push({y, x});
            }
        }

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int y_ = y + OFFSET[dir][0];
                    int x_ = x + OFFSET[dir][1];

                    if (isIn(y_, x_) && grid[y_][x_] == ORANGE) {
                        grid[y_][x_] = ROTTEN;
                        q.push({y_, x_});
                    }
                }
            }
            minutes++;
        }
        return minutes;
    }

};
