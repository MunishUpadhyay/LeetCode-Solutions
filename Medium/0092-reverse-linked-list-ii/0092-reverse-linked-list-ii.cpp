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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head -> next == NULL)
            return head;
            
        if(left == right)
            return head;

        ListNode* temp = head;

        ListNode* leftNode = nullptr;
        ListNode* leftPrev = nullptr;

        int val = 1;
        while(val <= left) {
            if(val == left - 1)
                leftPrev = temp;

            else if(val == left)
                leftNode = temp;

            val++;
            temp = temp -> next;
        }

        int range = right - left + 1;
        ListNode* current = leftNode;
        ListNode* prev = nullptr;

        while(range--) {
            ListNode* next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }

        if (leftPrev)
            leftPrev->next = prev;
        else
            head = prev;

        leftNode -> next = current;

        return head;
    }
};