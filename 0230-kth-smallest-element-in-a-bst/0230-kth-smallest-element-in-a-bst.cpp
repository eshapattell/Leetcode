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
int count;

int getAns(TreeNode* root){
    if(!root)return -1;

    
    int l = getAns(root->left);
    if(l != -1) return l;

    count--;
    if(count ==0){
        return root->val;
    }

    int r = getAns(root->right);
    return r;
}
    int kthSmallest(TreeNode* root, int k) {
        count=k;
        return getAns(root);
        

    }
};