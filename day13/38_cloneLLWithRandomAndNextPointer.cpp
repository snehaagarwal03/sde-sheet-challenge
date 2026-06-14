/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* temp = head;

        // create copy nodes and insert them in between
        while(temp) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }

        // set random pointers of copied nodes
        temp = head;
        while(temp) {
            if(temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // separate original and copied lists
        temp = head;
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;

        while(temp) {
            Node* copyNode = temp->next;
            temp->next = copyNode->next;
            copyTail->next = copyNode;
            copyTail = copyNode;
            temp = temp->next;
        }

        return dummy->next;    
    }
};