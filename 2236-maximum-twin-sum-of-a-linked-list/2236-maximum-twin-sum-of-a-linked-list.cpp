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
    int pairSum(ListNode* head) {
        // step 1: find mid
        ListNode* mid = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            mid = mid->next;
            fast = fast->next->next;
        }

        // step 2: reverse from mid to end
        ListNode* prev = nullptr;
        while (mid) {
            ListNode* next = mid->next;
            mid->next = prev;

            prev = mid;
            mid = next;
        }

        // step 3: two pointer from first list and second list
        ListNode* first = head;
        ListNode* second = prev;
        int ans = INT_MIN;

        while (first && second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};