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
    TreeNode* deleteNode(TreeNode* root, int key) {
        deleteN(root,key);
        return root;
    }
    void deleteN(TreeNode* &root,int key){
        if(root==nullptr) return;

        if(root->val<key){
            deleteN(root->right,key);
        }else if(root->val>key){
            deleteN(root->left,key);
        }else{
            if(root->left==nullptr){
                root=root->right;
            }
            else if(root->right==nullptr){
                root=root->left;
            }
            else{
                TreeNode* nn = findmin(root->right);
                root->val=nn->val;
                deleteN(root->right,nn->val);
            }
        }
    }
    TreeNode* findmin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
};