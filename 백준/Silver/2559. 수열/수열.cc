#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int sum = 0;
    vector<int> prefix(N, 0);
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        sum += temp;
        prefix[i] = sum;
    }
    
    int answer = prefix[K - 1];
    for (int i = K; i < N; i++) {
        answer = max(answer, prefix[i] - prefix[i - K]);
    }
    cout << answer;
    
    return 0;
}
