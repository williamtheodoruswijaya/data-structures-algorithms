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
        ListNode* dummy = new ListNode(0, head);

        // set both left and right to head
        ListNode* left = dummy;
        ListNode* right = dummy;

        // move right until right == n
        for (int i = 0; i < n + 1; i++) {
            right = right->next;
        }

        // slide the window (right and left)
        while (right) {
            left = left->next;
            right = right->next;
        }

        // left would be positioned 
        left->next = left->next->next;

        return dummy->next;
    }
};