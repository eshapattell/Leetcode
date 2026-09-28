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
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        int max_width = 1;

        // pair = {node, index}
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while (!q.empty()) {

            int n = q.size();

            // Leftmost and rightmost positions of this level
            long long leftmost = q.front().second;
            long long rightmost = q.back().second;

            // Calculate current width
            max_width = max(
                max_width,
                (int)(rightmost - leftmost + 1)
            );

            for (int i = 0; i < n; i++) {

                // Get the pair
                auto top = q.front();
                q.pop();

                // Get node
                TreeNode* node = top.first;

                // Normalize index
                long long index = top.second - leftmost;

                // Left child
                if (node->left != NULL) {
                    q.push({
                        node->left,
                        2 * index + 1
                    });
                }

                // Right child
                if (node->right != NULL) {
                    q.push({
                        node->right,
                        2 * index + 2
                    });
                }
            }
        }

        return max_width;
    }
};