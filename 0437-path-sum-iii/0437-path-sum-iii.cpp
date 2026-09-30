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

    int count = 0;
    long long sum = 0;
    unordered_map<long long, int> mp;

    void solve(TreeNode* root, long long targetSum) {

        if (root == NULL) {
            return;
        }

        // Add current node value
        sum += root->val;

        // Check previous prefix sums
        if (mp[sum - targetSum] > 0) {
            count += mp[sum - targetSum];
        }

        // Store current prefix sum
        mp[sum]++;

        // Go left
        solve(root->left, targetSum);

        // Go right
        solve(root->right, targetSum);

        // Backtrack
        mp[sum]--;
        sum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {

        // Reset global variables
        count = 0;
        sum = 0;
        mp.clear();

        // Prefix sum before starting the tree
        mp[0] = 1;
        solve(root, targetSum);
        return count;
    }
};