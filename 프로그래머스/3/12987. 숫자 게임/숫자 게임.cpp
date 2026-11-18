#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int answer = 0;
    int a = 0, b = 0;
    for (; a < A.size(); a++) {
        if (A[a] < B[b]) {
            answer++;
            b++;
        }
    }
    
    return answer;
}