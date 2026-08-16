/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* nextNode = curr->next;

                // Flatten the child list
                Node* childHead = flatten(curr->child);

                // Connect current node with child
                curr->next = childHead;
                childHead->prev = curr;

                // Child pointer must become NULL
                curr->child = NULL;

                // Find end of flattened child list
                Node* tail = childHead;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                // Connect child tail with original next node
                tail->next = nextNode;

                if (nextNode != NULL) {
                    nextNode->prev = tail;
                }

                // Continue from child tail
                curr = tail;
            }

            curr = curr->next;
        }

        return head;
    }
};