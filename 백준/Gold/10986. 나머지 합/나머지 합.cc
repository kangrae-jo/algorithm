#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    int sum = 0;
    vector<int> prefix(N, 0);
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        
        sum = (sum + (temp % M)) % M;
        prefix[i] = sum;
    }
    
    vector<long long> count(M, 0);
    count[0] = 1;  // 빈 누적합 포함

    for (int i = 0; i < N; i++) {
        count[prefix[i]]++;
    }

    long long answer = 0;
    for (int r = 0; r < M; r++) {
        answer += count[r] * (count[r] - 1) / 2;
    }
    
    cout << answer << '\n';
    
    return 0;
}