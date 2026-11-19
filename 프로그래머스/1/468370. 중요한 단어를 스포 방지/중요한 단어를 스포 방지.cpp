#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int n = message.size();
    vector<bool> hidden(n, false);
    for (const vector<int>& spoiler_range : spoiler_ranges) {
        for (int i = spoiler_range[0]; i <= spoiler_range[1]; i++) hidden[i] = true;
    }
    
    set<string> spoilers, normals;
    string temp = "";
    bool is_spoiler = false;
    for (int i = 0; i <= n; i++) {
        char c = message[i];
        if (c == ' ' || i == n) {
            if (is_spoiler) spoilers.insert(temp);
            else normals.insert(temp);
            is_spoiler = false;
            temp = "";
        } else {
            temp += c;
            if (hidden[i]) is_spoiler = true;
        }
    }
    
    int answer = 0;
    for (const string& spoiler : spoilers) {
        if (normals.count(spoiler) == 0) answer++;
    }
    
    return answer;
}