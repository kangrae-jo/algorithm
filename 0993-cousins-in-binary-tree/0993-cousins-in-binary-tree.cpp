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
    bool isCousins(TreeNode* root, int x, int y) {
        return level(root, x, 0) == level(root, y, 0) && !isSiblings(root, x, y);
    }

    int level(TreeNode* node, int val, int depth) {
        if (node == nullptr) return 0;
        if (node->val == val) return depth;

        int left = level(node->left, val, depth + 1);
        if (left != 0) return left;

        return level(node->right, val, depth + 1);
    }

    bool isSiblings(TreeNode* node, int x, int y) {
        if (node == nullptr) return false;
        if (node->left && node->right) {
            if ((node->left->val == x && node->right->val == y) ||
                (node->left->val == y && node->right->val == x)) return true;
        }
        return isSiblings(node->left, x, y) || isSiblings(node->right, x, y);
    }
};
