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
  bool helper(TreeNode *root, TreeNode *min, TreeNode *max) {
    // Empty subtree is always a valid BST
    if (root == NULL)
      return true;

    // Current node must be strictly greater than the lower bound
    if (min != NULL && root->val <= min->val)
      return false;

    // Current node must be strictly less than the upper bound
    if (max != NULL && root->val >= max->val)
      return false;

    // Right subtree: current node becomes the new lower bound
    // Left subtree: current node becomes the new upper bound
    return helper(root->right, root, max) && helper(root->left, min, root);
  }
  bool isValidBST(TreeNode *root) {
    // Start with no bounds on either side
    return helper(root, NULL, NULL);
  }
};