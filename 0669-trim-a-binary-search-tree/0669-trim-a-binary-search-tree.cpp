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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //if null
        if(root ==NULL)return root;
        
        //if it is in range
        if (root->val >= low && root->val <= high) { 
           //we check both sides
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        //if root val less than low we check only right side as its left would also have lower val than low
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        //if root val more than high, we check only left side as its right would also have higher val than high  
        return trimBST(root->left, low, high);
    }
};