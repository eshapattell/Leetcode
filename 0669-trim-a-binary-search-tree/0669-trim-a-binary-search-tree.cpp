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
//maintaining a parent
    TreeNode* getAns(TreeNode* root, int low, int high, TreeNode* parent){
        //if null
        if(root ==NULL)return root;

        //if in range
        if (root->val >= low && root->val <= high) { 
            root->left = getAns(root->left, low, high, root);
            root->right = getAns(root->right, low, high, root);
            return root;
        }

        //if root val less than low
        if (root->val < low) {
            if (parent != NULL){
                parent->left = root->right;
            }
            return getAns(root->right, low, high, parent);
        }

        //if root val more than high
        if (root->val > high) {
            if (parent != NULL)
                parent->right = root->left;

            return getAns(root->left, low, high, parent);
        }

        return root;

    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return getAns(root, low, high, NULL);
    }
};



        