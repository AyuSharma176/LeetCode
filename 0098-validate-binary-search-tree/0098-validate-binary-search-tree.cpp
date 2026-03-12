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
    struct bstpair{
        bool isbst=true;
        long long maxi=LONG_MIN;
        long long mini=LONG_MAX;
    };
    bstpair isvalid(TreeNode* root){
        if(root==nullptr) return bstpair();

        bstpair lbst=isvalid(root->left);
        bstpair rbst=isvalid(root->right);
        bstpair sbst;
        sbst.mini=min((long long)root->val,min(lbst.mini,rbst.mini));
        sbst.maxi=max((long long)root->val,max(lbst.maxi,rbst.maxi));
        sbst.isbst= lbst.isbst && rbst.isbst  && lbst.maxi < root->val && rbst.mini > root->val;
        return sbst;
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root).isbst;
    }
};