
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* node = &dummy;
        while (node->next != nullptr && node->next->next != nullptr) {
            ListNode* first = node->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            node->next = second;

            node = first;
        }

        return dummy.next;
    }
};
