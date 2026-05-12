#include <vector>

using namespace std;

int dfs(vector<int>& numbers, const int target, int num, int depth) {
    if (depth == numbers.size()) {
        if (num == target) return 1;
        return 0;
    }
    
    return dfs(numbers, target, num + numbers[depth], depth + 1)
        + dfs(numbers, target, num - numbers[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}
