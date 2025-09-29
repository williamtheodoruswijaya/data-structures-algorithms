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
    void reorderList(ListNode* head) {
        // step 1: find mid
        ListNode* mid = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            mid = mid->next;
            fast = fast->next->next;
        }

        // step 2: reverse mid -> tail
        ListNode* prev = nullptr;
        while (mid) {
            ListNode* next = mid->next;
            mid->next = prev;

            prev = mid;
            mid = next;
        }

        // step 3: merge alternately
        ListNode* first = head;
        ListNode* second = prev;
        while (second->next) {
            ListNode* next1 = first->next;
            ListNode* next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }

        return;
    }
};