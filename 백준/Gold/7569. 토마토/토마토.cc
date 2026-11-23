#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int OFFSET [6][3] = { 
    {0, 1, 0},
    {0, 0, 1}, 
    {0, -1, 0}, 
    {0, 0, -1}, 
    {1, 0, 0}, 
    {-1, 0, 0}
};

bool isIn(int h, int y, int x, int H, int N, int M) {
    return 0 <= h && h < H && 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
    int N, M, H;
    cin >> M >> N >> H;
    
    queue<pair<int, pair<int, int>>> q;
    vector<vector<vector<int>>> board(H, vector<vector<int>> (N, vector<int> (M, 0)));
    for (int h = 0; h < H; h++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                int state;
                cin >> state;
                board[h][y][x] = state;
                if (state == 1) q.push({h, {y, x}});
            }
        }
    }
    
    // spread
    int answer = -1;
    while(!q.empty()) {
        answer++;

        int size = q.size();
        while (size--) {
            int h = q.front().first;
            auto [y, x] = q.front().second;
            q.pop();
            
            for (int dir = 0; dir < 6; dir++) {
                int h_ = h + OFFSET[dir][0];
                int y_ = y + OFFSET[dir][1];
                int x_ = x + OFFSET[dir][2];
                if (isIn(h_, y_, x_, H, N, M) && board[h_][y_][x_] == 0) {
                    board[h_][y_][x_] = 1;
                    q.push({h_, {y_, x_}});
                }
            }
        }
    }
    
    // check
    for (int h = 0; h < H; h++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (board[h][y][x] == 0) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }
    
    cout << answer << '\n';

    return 0;
}
