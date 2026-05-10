#include <vector>
#include <queue>

const char X = 'X';
const char O = 'O';
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    int N, M;

    void solve(vector<vector<char>>& board) {
        N = board.size();
        M = board[0].size();
        
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (board[y][x] == O && !isEdge(y, x)) {
                    board = check(board, y, x);
                }
            }
        }
    }

private:
    bool isEdge(int y, int x) {
        return y == 0 || y == N - 1 || x == 0 || x == M - 1;
    }

    bool isIn(int y, int x) {
        return y >= 0 && y < N && x >= 0 && x < M;
    }

    vector<vector<char>> check(vector<vector<char>> board, int sY, int sX) {
        vector<vector<char>> temp = board;
        queue<pair<int, int>> q;
        q.push({sY, sX});
        temp[sY][sX] = X;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (isEdge(y, x)) return board;

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0];
                int x_ = x + OFFSET[dir][1];

                if (isIn(y_, x_) && temp[y_][x_] == O) {
                    q.push({y_, x_});
                    temp[y_][x_] = X;
                }
            }
        }

        return temp;
    }
};
