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
    // we first calculate length difference between 2 linked list so that we can skip the extra nodes and start the traversal for both LL at the same point so distance travelled for both LL for comparison is same
    int getDifference(ListNode* headA, ListNode* headB) {
        int l1 = 0, l2 = 0;
        while (headA != NULL || headB != NULL) {
            if (headA != NULL) {
                l1++;
                headA = headA->next;
            }
            if (headB != NULL) {
                l2++;
                headB = headB->next;
            }
        }
        return l1 - l2;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = getDifference(headA, headB);

        // we are moving the pointers of LL to match a common point and stop when diff becomes zero
        if (diff > 0)
            while (diff--) headA = headA->next;
        else 
            while (diff++) headB = headB->next;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};