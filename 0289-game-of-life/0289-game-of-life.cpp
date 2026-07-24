
// LIVE -> 이웃 LIVE 2~3개가 아니면 DEAD
// DEAD -> 이웃 LIVE 3개면 LIVE

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();

        vector<vector<int>> result(n, vector<int> (m));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++){
                int surround = count(board, y, x);
                if (board[y][x] == LIVE) {
                    if (surround == 2 || surround == 3) result[y][x] = LIVE;
                    else result[y][x] = DEAD;
                }
                if (board[y][x] == DEAD) {
                    if (surround == 3) result[y][x] = LIVE;
                    else result[y][x] = DEAD;
                }
            }
        }
        board = result;
    }

private:
    const int DEAD = 0;
    const int LIVE = 1;
    const int OFFSET[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

    int n, m;

    bool isIn(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }

    int count(vector<vector<int>>& board, int y, int x) {
        int answer = 0;
        for (int dir = 0; dir < 8; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];

            if (isIn(y_, x_) && board[y_][x_] == LIVE) answer++;
        }
        return answer;
    }
};
