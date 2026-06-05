/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            length++;
        }

        if (length == n) {
            return head->next;
        }

        cur = head;
        int prevOfTarget = length - n - 1;
        for (int i = 0; i < prevOfTarget; i++) {
            cur = cur->next;
        }

        cur->next = cur->next->next;
        return head;
    }
};
