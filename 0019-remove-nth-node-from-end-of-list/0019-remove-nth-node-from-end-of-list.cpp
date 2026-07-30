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
        ListNode* low= head;
        ListNode* high=head;
        ListNode* tempDelete;

        for(int i=0;i<n;i++){
            high= high->next;
        }
        if (high == NULL) {
            return head->next;
        }
        while(high->next != NULL){
            high= high->next;
            low= low->next;
        }
        ListNode* x= low->next;
        low->next =low->next->next;
        tempDelete= x;
        delete tempDelete;
        return head;
    }
};