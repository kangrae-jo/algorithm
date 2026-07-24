
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == THIEF) q.push({y, x});
            }
        }

        vector<vector<int>> distances = process(q, n);
        int min = 0;
        int max = 1000;

        while (min < max) {
            int mid = (min + max + 1) / 2;

            if (canBridge(mid, distances, n)) min = mid;
            else max = mid - 1;
        }
        
        return min;
    }

private:
    const int THIEF = 1;
    const int EMPTY = 0;
    const int OFFSET[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    bool isIn(int y, int x, int n) { return 0 <= y && y < n && 0 <= x && x < n; }

    vector<vector<int>> process(queue<pair<int, int>> q, int n) {
        vector<vector<int>> distances(n, vector<int>(n, -1));

        queue<pair<int, int>> thieves = q;
        while (!thieves.empty()) {
            auto [y, x] = thieves.front();
            thieves.pop();
            distances[y][x] = 0;
        }

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0];
                int x_ = x + OFFSET[dir][1];

                if (isIn(y_, x_, n) && distances[y_][x_] == -1) {
                    distances[y_][x_] = distances[y][x] + 1;
                    q.push({y_, x_});
                }
            }
        }
        return distances;
    }   

    bool canBridge(int mid, vector<vector<int>>& distances, int n) {
        if (distances[0][0] < mid) return false;

        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) { 
            auto [y, x] = q.front();
            q.pop();

            if (y == n - 1 && x == n - 1) return true;

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0];
                int x_ = x + OFFSET[dir][1];
                if (isIn(y_, x_, n) && !visited[y_][x_] && distances[y_][x_] >= mid) {
                    q.push({y_, x_});
                    visited[y_][x_] = true;
                }
            }
        }

        return false;
    }
};
