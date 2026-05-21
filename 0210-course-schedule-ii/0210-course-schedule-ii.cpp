#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (vector<int>& prerequisite : prerequisites) {
            int in = prerequisite[0];
            int out = prerequisite[1];
            graph[out].push_back(in);
            indegree[in]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> result;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            result.push_back(cur);
            
            for (int next : graph[cur]) {
                if (--indegree[next] == 0) q.push(next);
            }
        }

        if (*max_element(indegree.begin(), indegree.end()) != 0) return {};
        return result;
    }
};
