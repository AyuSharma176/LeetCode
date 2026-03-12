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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        int sd=height(root->left)+height(root->right)+2;
        return max(sd,max(rd,ld));
    }
    int height(TreeNode* root){
        if(root==nullptr){
            return -1;
        }
        return max(height(root->left),height(root->right))+1;
    }
};