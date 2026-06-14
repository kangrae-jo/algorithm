/*
    우선순위 큐를 두개 두고 size가 같도록 관리하면 중간값 찾기 쉬움
    minHeap : 오름차순 정렬 / 큰 값들의 집합   / [5, 7, 8]
    maxHeap : 내림차순 정렬 / 작은 값들의 집합 / [4, 3, 1]
*/

class MedianFinder {
private: 
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int> maxHeap;

    template <typename Src, typename Dest>
    void moveTop(Src& src, Dest& dest) {
        dest.push(src.top());
        src.pop();
    }

public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        moveTop(maxHeap, minHeap);
    
        if (minHeap.size() > maxHeap.size()) {
            moveTop(minHeap, maxHeap);
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */