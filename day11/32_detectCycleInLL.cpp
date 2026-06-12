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
        //we are storing addresses of visited nodes
        //this also handles duplicate values in the linked list as we are storing address
        unordered_set<ListNode*> visited;
        while (head != NULL) {
            //we find the node address in the set and if it exists then find() returns and iterator to it and as its not equal to end_iterator so condition is true, and when no matching address is found then find() means that it has searched whole set and didn't find anything so it returns end_iterator 
            if (visited.find(head) != visited.end()) {
                return true;
            }
            //marking current node as visited
            visited.insert(head);
            head = head->next; 
        }
        return false;   //when no node was find twice in the set so no cycle, returns false
    }
};