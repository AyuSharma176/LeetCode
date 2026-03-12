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
    struct diapair{
        int ht=-1;
        int dt=0;
    };

    diapair diameter(TreeNode* root){
        if(root==nullptr){
            return diapair();
        }
        diapair ldp= diameter(root->left);
        diapair rdp= diameter(root->right);
        int sd=ldp.ht+rdp.ht+2;
        diapair sdp;
        sdp.dt=max(sd,max(ldp.dt,rdp.dt));
        sdp.ht=max(ldp.ht,rdp.ht)+1;
        return sdp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).dt;
    }
};