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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;

        ListNode* temp1 = head;
        ListNode* temp2 = head -> next;

        ListNode* dummy = new ListNode(-1);
        ListNode* pointer = dummy;

        while(temp1 != NULL && temp2 != NULL) {
            ListNode* nextPair = temp2 -> next;

            pointer -> next = temp2;
            temp2 -> next = temp1;

            temp1 -> next = nextPair;

            pointer = temp1;

            temp1 = nextPair;

            if (temp1 != NULL)
                temp2 = temp1->next;
            else
                temp2 = NULL;
        }

        return dummy -> next;
    }
};