class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        // 1) 중간 찾기
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 2) 반전
        ListNode* prev = nullptr;
        while (second != nullptr) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        ListNode* first = head;
        second = prev;

        // 3) 병합
        while (second != nullptr) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};

/*
    문제 - 뒤에 있는 노드부터 역순으로 끼워넣어야하는데, 헤드를 잃어버린다.
    해결 - 앞으로 reorder되는 node는 뒤에서부터 절반 그 이상을 넘지 않는다.
            뒤쪽 절반을 나타내는 헤드를 찾자.

    문제 - 앞쪽 절반에 하나씩 끼워넣어야하는데, 뒤쪽 절반의 뒤에서부터 넣기 힘들다.
    해결 - n, n-1, n-2, ... 가 되도록 뒤쪽 절반 헤드를 reverse하자.

    1. 중간 찾기
    2. 뒤쪽 절반 반전
    3. 앞쪽·뒤쪽 번갈아 병합
*/