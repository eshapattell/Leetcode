/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //if empty or list has one node it cant be in cycle
        if(head == NULL || head->next == NULL) return false;

        //both are starting from head;
        ListNode* slow= head;
        ListNode* fast= head;

        // Fast moves 2 steps, so fast->next should be valid as well with fast pointer
        while(fast!= NULL && fast->next != NULL){
            //fast pointer moves 2steps ahead
            fast= fast->next->next;
            //moves 1 step
            slow= slow->next;

        //if cycle exist then both the pointers will catch up with each other
        if(fast== slow) return true;
        }

        //fast reaches the end so no cycloe exist
        return false;
    }
};
//Time complexity: O(N)
//Space complexity: O(1)