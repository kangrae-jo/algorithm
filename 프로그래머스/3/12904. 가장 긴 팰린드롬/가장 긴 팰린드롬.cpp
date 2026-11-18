#include <algorithm>
#include <string>

using namespace std;

int process(const string& s, int left, int right) {
    int temp = 0;
    while (0 <= left && right < s.size()) {
        if (s[left--] == s[right++]) temp += 2;
        else break;
    }
    return temp;
}

int solution(string s) {
    int n = s.size();    
    int answer = 0;
    for (int mid = 0; mid < n; mid++) {
        int temp = max(
            process(s, mid - 1, mid + 1) + 1,
            process(s, mid, mid + 1)
        );
        answer = max(answer, temp);
    }
    
    return answer;
}