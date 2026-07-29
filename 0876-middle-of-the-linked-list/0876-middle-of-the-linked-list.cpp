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
    ListNode* middleNode(ListNode* head) {
        //we create one slow which would move one step at a time
        ListNode* slow = head;
        //we create one fast which would take two steps at a time
        ListNode* fast = head;
        //if in even case we want the first middle ele we will simply place fast at head->next

        //when fast reaches null that time slow would be pointing to the middle one
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};