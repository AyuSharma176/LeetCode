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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode* nn = new TreeNode(val);
            return nn;
        }
        insert(root,val);
        return root;
    }
    void insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->val > val) {
            TreeNode* nn = new TreeNode(val);
            root->left = nn;
        } else if (root->right == nullptr && root->val < val) {
            TreeNode* nn = new TreeNode(val);
            root->right = nn;
        }
        if (root->val > val) {
            insert(root->left, val);
        } else if (root->val < val) {
            insert(root->right, val);
        }
    }
};