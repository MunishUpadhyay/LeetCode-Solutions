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
    ListNode* doubleIt(ListNode* head) {
        stack<int> st1;
        stack<int> st2;

        ListNode* temp = head;
        while(temp != NULL) {
            st1.push(temp -> val);
            temp = temp -> next;
        }

        int carry = 0;

        while(!st1.empty()) {
            int product = 2 * st1.top() + carry;
            int val = product % 10;
            carry = product / 10;

            st2.push(val);
            st1.pop();
        }

        if(carry > 0)
            st2.push(carry);

        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        while(!st2.empty()) {
            curr -> next = new ListNode(st2.top());
            curr = curr -> next;
            st2.pop();
            
        }

        return dummyNode -> next;
    }
};