#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev(n), next(n);
    for (int i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = i + 1 < n ? i + 1 : -1;
    }

    int cur = k;
    stack<int> canceled;
    for (const string& command : cmd) {
        if (command[0] == 'U') {
            int X = stoi(command.substr(2));
            while (X--) cur = prev[cur];
        } else if (command[0] == 'D') {
            int X = stoi(command.substr(2));
            while (X--) cur = next[cur];
        } else if (command[0] == 'C') {
            canceled.push(cur);
            if (prev[cur] != -1) next[prev[cur]] = next[cur];
            if (next[cur] != -1) prev[next[cur]] = prev[cur];
            cur = next[cur] != -1 ? next[cur] : prev[cur];
        } else if (command[0] == 'Z') {
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
