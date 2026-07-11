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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currPath;
        dfs(root, 0, currPath, ans, targetSum);       

        return ans;
    }

    void dfs(TreeNode* root, int sum, vector<int>& currPath, vector<vector<int>>& ans, int targetSum) {
        if(!root) return;

        sum += root -> val;
        currPath.push_back(root -> val);

        if(!root -> left && !root -> right && sum == targetSum) {
            ans.push_back(currPath);
        }

        dfs(root -> left, sum, currPath, ans, targetSum);
        dfs(root -> right, sum, currPath, ans, targetSum);

        currPath.pop_back();
    }
};