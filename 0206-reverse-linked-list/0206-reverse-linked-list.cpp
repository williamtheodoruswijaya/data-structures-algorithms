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
    ListNode* reverseList(ListNode* head) {
        // s-case: if head is None, early return
        if (!head) return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while (next) {
            // 1. move curr->next to prev
            curr->next = prev;

            // 2. move prev to curr
            prev = curr;

            // 3. move curr to next
            curr = next;

            // 4. move next
            next = next->next;
        }

        curr->next = prev;
        return curr;
    }
};