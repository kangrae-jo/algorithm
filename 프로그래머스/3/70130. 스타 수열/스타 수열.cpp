#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int CHECKED = -1;

int solution(vector<int> a) {
    int n = a.size(), answer = 0;
    unordered_map<int, int> numbers;
    for (int i = 0; i < n; i++) {
        numbers[a[i]]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (numbers[a[i]] <= answer) continue;
        numbers[a[i]] = CHECKED;
        
        int temp = 0;
        for (int j = 0; j < n - 1;) {
            if (a[j] != a[j + 1] && (a[i] == a[j] || a[i] == a[j + 1])) {
                temp++;
                j += 2;
            }
            else j++;
        }
        answer = max(answer, temp);
    }
    
    return answer * 2;
}
