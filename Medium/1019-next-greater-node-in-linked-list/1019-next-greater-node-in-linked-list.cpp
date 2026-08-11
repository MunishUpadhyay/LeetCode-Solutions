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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;

        while(curr != NULL) {
            ListNode* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
            cnt++;
        }

        stack<int> st;
        vector<int> ans(cnt);

        while(prev != NULL) {
            while(!st.empty() && st.top() <= prev -> val) {
                st.pop();
            }
            ans[--cnt] = st.empty() ? 0 : st.top();
            st.push(prev -> val);
            prev = prev -> next;
        }

        return ans;
    }
};