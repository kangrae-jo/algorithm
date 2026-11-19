#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int n = message.size();
    vector<bool> hidden(n, false);
    for (const auto& spoiler_range : spoiler_ranges) {
        for (int i = spoiler_range[0]; i <= spoiler_range[1]; i++) hidden[i] = true;
    }

    set<string> spoiler_words, normal_words;
    string temp = "";
    bool is_spoiler = false;
    for (int i = 0; i <= n; i++) {
        if (i == n || message[i] == ' ') {
            if (is_spoiler) spoiler_words.insert(temp);
            else normal_words.insert(temp);
            temp = "";
            is_spoiler = false;
        } else {
            temp += message[i];
            if (hidden[i]) is_spoiler = true;
        }
    }

    int answer = 0;
    for (const string& spoiler_word : spoiler_words) {
        if (!normal_words.count(spoiler_word)) answer++;
    }
    
    return answer;
}