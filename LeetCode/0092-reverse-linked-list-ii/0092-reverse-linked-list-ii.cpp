class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);

        ListNode* beforeLeft = &dummy;
        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        ListNode* current = beforeLeft->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* target = current->next;
            current->next = target->next;
            target->next = beforeLeft->next;
            beforeLeft->next = target;
        }

        return dummy.next;
    }
};
