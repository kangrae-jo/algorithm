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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> answer;
        while (!q.empty()) {
            vector<int> temp; 
            int size = q.size();

            while (size--) {
                TreeNode* cur = q.front();
                q.pop();

                temp.push_back(cur->val);
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            answer.push_back(*max_element(temp.begin(), temp.end()));
        }

        return answer;
    }  
};
