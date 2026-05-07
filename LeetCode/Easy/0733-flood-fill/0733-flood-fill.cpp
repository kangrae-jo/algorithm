#include <queue>
#include <vector>

using namespace std;

const int OFFSET[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sy, int sx, int color) {
        int target = image[sy][sx];
        if (target == color) return image;

        int N = image.size();
        int M = image[0].size();

        queue<pair<int, int>> q;
        q.push({sy, sx});
        image[sy][sx] = color;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0];
                int x_ = x + OFFSET[dir][1];

                if (isIn(y_, x_, N, M) && image[y_][x_] == target) {
                    q.push({y_, x_});
                    image[y_][x_] = color;
                }
            }
        }

        return image;
    }

private:
    bool isIn(int y, int x, int N, int M) {
        return 0 <= y && y < N && 0 <= x && x < M;
    }
};