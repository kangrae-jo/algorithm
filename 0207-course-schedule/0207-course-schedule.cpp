#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // add indegree of courses
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int want = prerequisites[i][0];
            int prev = prerequisites[i][1];

            graph[prev].push_back(want);
            indegree[want]++;
        }

        // find courses (if indegree == 0, can start)
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // processing topologic sort
        while (!q.empty()) {
            int prev = q.front(); 
            q.pop();

            for (int want : graph[prev]) {
                if (--indegree[want] == 0) q.push(want);
            }
        }

        // is finish?
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] > 0) return false;
        }
        return true;
    }
};

// 15:35 ~ 16:06