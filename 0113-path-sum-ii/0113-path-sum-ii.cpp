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
    void getAns(TreeNode* root, int targetSum,
               vector<int>& path, vector<vector<int>>& ans) {

        if (root == NULL) {
            return;
        }

        // Add current node to path
        path.push_back(root->val);

        // Check if current node is a leaf
        if (root->left == NULL && root->right == NULL) {

            // Check if this root-to-leaf path has required sum
            if (targetSum == root->val) {
                ans.push_back(path);
            }
            // Backtrack
            path.pop_back();
            return;
        }

        // Go to left subtree
        getAns(root->left, targetSum - root->val, path, ans);
        // Go to right subtree
        getAns(root->right, targetSum - root->val, path, ans);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        getAns(root, targetSum, path, ans);
        return ans;
    }
};