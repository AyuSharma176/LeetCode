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
    int kthSmallest(TreeNode* root, int k) {
        set<int> set;
        kth(root, set);
        auto it = set.begin();
        advance(it, k-1);

        return *it;
    }
    void kth(TreeNode* root, set<int>& set) {
        if (root == nullptr) {
            return;
        }
        set.insert(root->val);
        kth(root->left, set);
        kth(root->right, set);
    }
};