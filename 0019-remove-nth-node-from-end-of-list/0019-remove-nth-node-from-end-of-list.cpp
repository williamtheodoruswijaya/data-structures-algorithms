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
        // step 1: get size/length of the list
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }

        // step 2: get the value on n from front
        int k = size - n;

        // step 3: go to k-th - 1 node
        curr = head;
        int x = 0;
        while (x < k - 1) {
            x++;
            curr = curr->next;
        }

        // step 4: delete the k-th node
        if (n == size) {
            head = curr->next;
        }else if (n == 1 && size != 1) {
            curr->next = nullptr;
        } else if (n == 1 && size == 1) {
            head = nullptr;
        } else {
            ListNode* next = curr->next->next;
            curr->next = next;
        }

        return head;
    }
};