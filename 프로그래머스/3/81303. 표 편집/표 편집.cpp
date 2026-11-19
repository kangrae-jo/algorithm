#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmds) {
    vector<int> prev(n), next(n);
    for (int i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = i + 1 < n ? i + 1 : -1;
    }
    
    int cur = k;
    stack<int> canceled;
    for (const string& cmd : cmds) {
        if (cmd[0] == 'U') {
            int x = stoi(cmd.substr(2));
            while(x--) cur = prev[cur];
        } else if (cmd[0] == 'D') {
            int x = stoi(cmd.substr(2));
            while(x--) cur = next[cur];
        } else if (cmd[0] == 'C') {
            canceled.push(cur);
            if (prev[cur] != -1) next[prev[cur]] = next[cur];
            if (next[cur] != -1) prev[next[cur]] = prev[cur];
            cur = next[cur] != -1 ? next[cur] : prev[cur];
        } else if (cmd[0] == 'Z') {
            int z = canceled.top();
            canceled.pop();
            
            if (prev[z] != -1) next[prev[z]] = z;
            if (next[z] != -1) prev[next[z]] = z;
        }
    }
    
    string answer(n, 'O');
    while (!canceled.empty()) {
        answer[canceled.top()] = 'X';
        canceled.pop();
    }
    
    return answer;
}