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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ptr=0;
        return create(INT_MAX,ptr,preorder);
    }
    TreeNode* create(int up,int& ptr,vector<int>& preorder){
        if(ptr==preorder.size()  || preorder[ptr] >= up) return NULL;

        TreeNode* nn=new TreeNode(preorder[ptr++]);
        nn->left=create(nn->val,ptr,preorder);
        nn->right=create(up,ptr,preorder);
        return nn;
    }
};