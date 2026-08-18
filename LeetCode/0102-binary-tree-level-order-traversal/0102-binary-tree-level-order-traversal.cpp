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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> answer;
        while(!q.empty()) {
            vector<int> nodes;
            int size = q.size();
            while(size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node != nullptr) {
                    nodes.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (q.empty()) break;
            answer.push_back(nodes);
        }

        return answer;
    }
};
