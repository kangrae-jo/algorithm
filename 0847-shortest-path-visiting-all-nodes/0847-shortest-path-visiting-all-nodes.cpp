class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisited = (1 << n) - 1;  // 모든 노드를 방문한 목표 mask.

        queue<pair<int, int>> pq;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        for (int node = 0; node < n; node++) {
            int mask = 1 << node;       // 각 노드를 방문 상태로 표시.
            pq.push({node, mask});
            visited[node][mask] = true;
        }

        int depth = 0;
        while (!pq.empty()) {
            int size = pq.size();
            while (size--) {
                auto [node, mask] = pq.front();
                pq.pop();

                if (mask == allVisited) return depth;
                
                for (int next : graph[node]) {
                    int nextMask = mask | (1 << next);  // next노드를 방문 처리 후 or연산으로 합함.
                    if (visited[next][nextMask]) continue;

                    pq.push({next, nextMask});
                    visited[next][nextMask] = true;
                }
            }
            depth++;
        }

        return -1;
    }
};
/*
    알아야하는 비트 연산.
        1 << n : n번째 비트만 1로 설정
        (1 << n) - 1 : 하위 n개 비트를 모두 1로 설정
    
    Why using Bitmask?
        어떤 노드에 갔을 때, 내가 방문했던 노드들을 알고 싶어서.
        예를 들어, 지금 노드가 0이라도, 예전에 방문했던 노드 정보는 다를 수 있다.
        그리고 그것이 정답(최단 거리)에 영향을 준다.
        요약하자면, "상태"는 "지금 위치 + 방문했던 노드"이고 "지금 위치"는 bfs로 "방문했던 노드"는 bitmask로 구현한다.
*/
