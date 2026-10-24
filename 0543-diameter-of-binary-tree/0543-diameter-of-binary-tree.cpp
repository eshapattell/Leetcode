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
    int diameter=0;

    int height(TreeNode* node){
        // Empty tree has height 0
        if(!node){
            return 0;
        }

        // Get height of left and right subtrees
        int left= height(node->left);
        int right= height(node->right);

        // Diameter passing through current node
        diameter= max(diameter, left+right);

        // Return height of current subtree
        return max(left, right) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
        
    }
};