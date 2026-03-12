/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        bool ok = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                TreeNode* rv = q.front();
                q.pop();
                v.push_back(rv->val);
                if (rv->left)
                    q.push(rv->left);
                if (rv->right)
                    q.push(rv->right); 
            }
            if (!ok) {
                reverse(v.begin(), v.end());
                
            }
            result.push_back(v);
            ok=!ok;
        }
        return result;
    }
};