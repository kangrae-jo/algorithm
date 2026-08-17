class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int key = 0;
        queue<pair<pair<int, int>, string>> pq;
        vector<vector<set<string>>> visited(n, vector<set<string>>(m));

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (grid[y][x] == START) {
                    pq.push({{y, x}, ""});
                    visited[y][x].insert("");
                } else if (islower(grid[y][x])) key++;
            }
        }

        int depth = 0;
        while (!pq.empty()) {
            int size = pq.size();
            while (size--) {
                auto [y, x] = pq.front().first;
                string keys = pq.front().second;
                pq.pop();

                if (key == keys.length()) return depth;
                
                for (int dir = 0; dir < 4; dir++) {
                    int y_ = y + OFFSET[dir][0];
                    int x_ = x + OFFSET[dir][1];

                    if (!isIn(y_, x_, n, m) || grid[y_][x_] == WALL) continue;

                    char cell = grid[y_][x_];
                    string nextKeys = keys;

                    if (islower(cell) && nextKeys.find(cell) == string::npos) {
                        nextKeys.push_back(cell);
                        //sort(nextKeys.begin(), nextKeys.end());
                    }

                    if (isupper(cell) && nextKeys.find(cell - 'A' + 'a') == string::npos) continue;
                    if (visited[y_][x_].find(nextKeys) != visited[y_][x_].end()) continue;
                    
                    visited[y_][x_].insert(nextKeys);
                    pq.push({{y_, x_}, nextKeys});
                }
            }
            depth++;
        }

        return -1;
    }

private:
    const char WALL = '#';
    const char START = '@';
    const int OFFSET[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    bool isIn(int y, int x, int n, int m) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }
};
