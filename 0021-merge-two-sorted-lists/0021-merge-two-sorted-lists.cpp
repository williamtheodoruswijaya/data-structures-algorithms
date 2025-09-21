/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 Illustration:
    curr1 = [1 -> 2 -> 4]
    curr2 = [1 -> 3 -> 4]

    res = [0 -> null]
    tail = res = [0 -> null]

    i = 0
        res = [0 -> 1 -> 3 -> 4]
        curr1 = [1 -> 2 -> 4]
        curr2 = [3 -> 4]
    
    i = 1
        res = [0 -> 1 -> 1 -> 2 -> 4]
        curr1 = [2 -> 4]
        curr2 = [3 -> 4]
    
    i = 2
        res = [0 -> 1 -> 1 -> 2 -> 4]
        curr1 = [4]
        curr2 = [3 -> 4]

    i = 3
        res = [0 -> 1 -> 1 -> 2 -> 3 -> 4]
        curr1 = [4]
        curr2 = [4]
    
    i = 4
        res = [0 -> 1 -> 1 -> 2 -> 3 -> 4]
        curr1 = [4]
        curr2 = null
    
    append curr that have a remaining value
        res = [0 -> 1 -> 1 -> 2 -> 3 -> 4 -> curr1]
        res = [0 -> 1 -> 1 -> 2 -> 3 -> 4 -> 4]
    
    return res->next which's [1 -> 1 -> 2 -> 3 -> 4 -> 4]
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. create two pointer pointing into each list (list1 & list2)
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        // 2. create an empty linked list [0 -> null] that'll act as the main sorted list
        ListNode res(0);

        // 3. create a pointer to [0 *-> null] so we can add the new element on 0 -> next
        ListNode* tail = &res;

        // 4. iterate through curr1 and curr2
        while (curr1 && curr2) {
            // 5. if curr1 < curr2, [0 -> curr1]
            if (curr1->val < curr2->val) {
                tail->next = curr1;
                curr1 = curr1->next;
            }
            // 6. if curr2 >= curr1, [0 -> curr2]
            else {
                tail->next = curr2;
                curr2 = curr2->next;
            }
            // 7. move tail (basically from [0 -> head] now on [head -> ...])
            tail = tail->next;
        }

        // 8. if one of the curr already null but the other either curr1 or curr2 isn't, [head -> ...] append the rest
        if (curr1) tail->next = curr1;
        if (curr2) tail->next = curr2;

        // 9. since res [0 -> ... -> ...], we exclude 0 from the results
        return res.next;
    }
};