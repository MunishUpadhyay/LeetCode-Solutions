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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while(temp1 != NULL || temp2 != NULL) {
            if(temp1) st1.push(temp1 -> val);
            if(temp2) st2.push(temp2 -> val);

            if(temp1) temp1 = temp1 -> next;
            if(temp2) temp2 = temp2 -> next;
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        ListNode* newNode;
        int carry = 0;

        while(!st1.empty() || !st2.empty()) {
            int sum = carry;

            if(!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }

            if(!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr -> next = newNode;
            curr = newNode;
        }
        if(carry) {
            newNode = new ListNode(carry);
            curr -> next = newNode;
        }

        ListNode* prev = NULL;
        ListNode* current = dummyNode->next;

        while(current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};