class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int n = 1;
        ListNode* node = head;
        while (node->next != nullptr) {
            node = node->next;
            n++;
        }

        k %= n;
        if (k == 0) {
            return head;
        }

        node->next = head;
        for (int i = 0; i < n - k; i++) {
            node = node->next;
        }

        ListNode* newHead = node->next;
        node->next = nullptr;

        return newHead;
    }
};