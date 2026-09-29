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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the tree is empty, create a new node with the given value and return it as the new root.
        if(root == NULL) return new TreeNode(val);

        // Compare the value to insert (val) with the current node's value.
        if (val > root->val)
            // If the value to insert is greater than the current node's value, recursively insert it into the right subtree.
            root->right = insertIntoBST(root->right, val);
        else
            // If the value to insert is less than or equal to the current node's value, recursively insert it into the left subtree.
            root->left = insertIntoBST(root->left, val);

        // Return the root of the modified tree after the insertion.
        return root;
    }
};