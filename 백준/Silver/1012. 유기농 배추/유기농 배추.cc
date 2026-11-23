#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int EMPTY = 0;
const int WALL = 1;
const int VISITED = 2;
const int OFFSET[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0,-1} };

bool isIn(int y, int x, int N, int M) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void bfs(vector<vector<int>>& board, int N, int M, int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    board[y][x] = VISITED;
    
    while(!q.empty()) {
        auto[y, x] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            if (isIn(y_, x_, N, M) && board[y_][x_] == WALL) {
                q.push({y_, x_});
                board[y_][x_] = VISITED;
            }
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int M, N, K;
        cin >> N >> M >> K;
        
        vector<vector<int>> board(N, vector<int> (M, EMPTY));
        
        while (K--) {
            int x, y;
            cin >> y >> x;
            board[y][x] = WALL;
        }
        
        int answer = 0;           
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (board[y][x] == WALL) {
                    bfs(board, N, M, y, x);
                    answer++;
                }
            }
        }
        cout << answer << '\n';
    }
    
    return 0;
}
