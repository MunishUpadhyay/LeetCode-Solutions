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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(int n, ListNode*& current) {
        if(n == 0) 
            return nullptr;
        
        TreeNode* left = buildTree(n / 2, current);
        TreeNode* root = new TreeNode(current->val);

        current = current -> next;

        root->left = left;
        root->right = buildTree(n - n / 2 - 1, current);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        int n = 0;

        while(temp != NULL) {
            n++;
            temp = temp -> next;
        }

        return buildTree(n, head);
    }
};