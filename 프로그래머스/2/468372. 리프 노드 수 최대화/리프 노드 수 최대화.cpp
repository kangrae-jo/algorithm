#include <algorithm>
#include <vector>

using namespace std;

int solution(int dist_limit, int split_limit) { 
    long answer = 0;
    for (long p2 = 1; p2 <= split_limit; p2 *= 2) {
        for (long p = p2; p <= split_limit; p *= 3) {
            long cost = 0, cur = 1;
            while (cur < p2) {
                cost += cur;
                cur *= 2;
            }
            while (cur < p) {
                cost += cur;
                cur *= 3;
            }
            if (cost > dist_limit) continue;
            
            long remains = dist_limit - cost;
            long b = (p * 3 <= split_limit) ? 3 : (p * 2 <= split_limit) ? 2 : 1;
            answer = max(answer, p + min(remains, p) * (b - 1));
        }
    }
    
    return (int) answer;
}