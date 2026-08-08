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
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return answer;
    }

private:
    int th = 0;
    int answer;

    void inOrder(TreeNode* node, int k) {
        if (node == nullptr) return;

        inOrder(node->left, k);
        th++;
        if (th == k) {
            answer = node->val;
            return;
        }
        inOrder(node->right, k);
    }
};
