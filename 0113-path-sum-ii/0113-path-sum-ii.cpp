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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> l;
        haspathsum(root, targetSum, l, result);
        return result;
    }
    void haspathsum(TreeNode* root, int target, vector<int>& l,
                    vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }
        l.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (target == root->val) {
                result.push_back(l);
            }
        }
        haspathsum(root->left, target - root->val, l, result);
        haspathsum(root->right, target - root->val, l, result);
        l.pop_back();
    }
};