#include <vector>
#include <queue>

using namespace std;

const int EMPTY = 0;
const int PATH = 1;
const int NEVER = 2;
const int OFFSET [4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

const int N = 50 * 2 + 1;
const int M = 50 * 2 + 1;

bool isEdge(const vector<int>& rec, const int& y, const int& x) {
    return y == rec[1] || y == rec[3] || x == rec[0] || x == rec[2];
}

bool isIn(int y, int x) { 
    return 0 <= y && y < N && 0 <= x && x < M; 
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> board(N, vector<int> (M, EMPTY));
    for (vector<int> rec : rectangle) {
        rec[0] *= 2;
        rec[1] *= 2;
        rec[2] *= 2;
        rec[3] *= 2;
        for (int y = rec[1]; y <= rec[3]; y++) {
            for (int x = rec[0]; x <= rec[2]; x++) {
                if (isEdge(rec, y, x) && board[y][x] != NEVER) board[y][x] = PATH;
                else board[y][x] = NEVER;
            }
        }
    }
    
    characterY *= 2;
    characterX *= 2;
    itemY *= 2;
    itemX *= 2;
    
    vector<vector<bool>> visited(N, vector<bool> (M, false));  

    queue<pair<int, int>> q;
    q.push({characterY, characterX});
    visited[characterY][characterX] = true;
    
    int answer = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [y, x] = q.front();
            q.pop();

            if (y == itemY && x == itemX) return answer / 2;
            
            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0]; 
                int x_ = x + OFFSET[dir][1];
                if (isIn(y_, x_) && board[y_][x_] == PATH && !visited[y_][x_]) {
                    q.push({y_, x_});
                    visited[y_][x_] = true;
                }
            }
        }
        answer++;
    }
    
    return answer / 2;
}
