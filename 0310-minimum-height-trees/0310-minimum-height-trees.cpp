#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        // make graph&degree table
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for (vector<int>& edge : edges) {
            int in = edge[0];
            int out = edge[1];

            graph[in].push_back(out);
            graph[out].push_back(in);

            degree[in]++;
            degree[out]++;
        }

        // degree == 1 is leaf
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        // n is odd? 
        // center node's size is 1 
        // or 2
        int remain = n;
        while (remain > 2) {
            int size = q.size();
            remain -= size;

            while (size--) {
                int cur = q.front();
                q.pop();

                for (int next : graph[cur]) {
                    if (--degree[next] == 1) q.push(next);
                }
            }
        }

        // make result from remains of q
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
// 23:10 ~ 23:28
