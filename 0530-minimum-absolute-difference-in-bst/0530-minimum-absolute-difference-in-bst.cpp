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
    int mini = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        diff(root, prev);
        return mini;
    }
    void diff(TreeNode* root, int& prev) {
        if (root == NULL) {
            return;
        }
        diff(root->left, prev);

        if (prev != -1) {
            int dif = abs(prev - root->val);
            mini = min(dif, mini);
        }
        prev = root->val;

        diff(root->right, prev);
    }
};