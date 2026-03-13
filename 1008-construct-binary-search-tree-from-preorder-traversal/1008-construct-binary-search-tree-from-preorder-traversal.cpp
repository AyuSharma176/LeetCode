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
        return create(preorder);
    }
    TreeNode* create(vector<int>& nums){
        if(nums.size()<=0){
            return nullptr;
        }
        TreeNode* nn= new TreeNode();
        nn->val=nums[0];
        vector<int> left=leftarr(nums,nums[0]);
        vector<int> right=rightarr(nums,nums[0]);
        nn->left=create(left);
        nn->right=create(right);
        return nn;
    }
    vector<int> leftarr(vector<int>& nums,int r){
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<r){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
    vector<int> rightarr(vector<int>& nums,int r){
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>r){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};