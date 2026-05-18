#include <iostream>
#include <queue>

using namespace std;

const int EMPTY = 0;
const int BLACK = 1;
const int WHITE = 2;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, EMPTY);
        for (int i = 0; i < n; i++) {
            if (colors[i] == EMPTY) {
                if (!bfs(graph, i, colors, BLACK)) {
                    return false;
                }
            }
        }

        return true;
    }

    int change(int color) {
        if (color == BLACK) return WHITE;
        return BLACK;
    }

    bool bfs(vector<vector<int>>& graph, int start, vector<int>& colors, int COLOR) {
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int cur = q.front();
                q.pop();

                colors[cur] = COLOR;

                for (int next : graph[cur]) {
                    if (colors[next] == COLOR) return false;
                    if (colors[next] == EMPTY) q.push(next);
                }
                
            }
            COLOR = change(COLOR);
        }
        return true;
    }
};

// 15:48 ~ 16:17