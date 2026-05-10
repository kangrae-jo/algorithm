#include <vector>
#include <queue>

using namespace std;

const char X = 'X';
const char O = 'O';
const char SAFE = '#';
const int OFFSET[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
public:
    int N, M;

    void solve(vector<vector<char>>& board) {
        N = board.size();
        M = board[0].size();

        for (int y = 0; y < N; y++) {
            if (board[y][0] == O) bfs(board, y, 0);
            if (board[y][M - 1] == O) bfs(board, y, M - 1);
        }
        for (int x = 0; x < M; x++) {
            if (board[0][x] == O) bfs(board, 0, x);
            if (board[N - 1][x] == O) bfs(board, N - 1, x);
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (board[y][x] == O) board[y][x] = X;
                else if (board[y][x] == SAFE) board[y][x] = O;
            }
        }
    }

private:
    bool isIn(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < M;
    }

    void bfs(vector<vector<char>>& board, int sY, int sX) {
        queue<pair<int, int>> q;
        q.push({sY, sX});
        board[sY][sX] = SAFE;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0];
                int x_ = x + OFFSET[dir][1];

                if (isIn(y_, x_) && board[y_][x_] == O) {
                    board[y_][x_] = SAFE;
                    q.push({y_, x_});
                }
            }
        }
    }
};
