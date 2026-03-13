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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums,0,nums.size()-1);
    }
    TreeNode* create(vector<int>& nums,int st,int ed){
        if(st>ed) return nullptr;
        int mid=st+(ed-st)/2;
        TreeNode* nn=new TreeNode();
        nn->val=nums[mid];
        nn->left=create(nums,st,mid-1);
        nn->right=create(nums,mid+1,ed);
        return nn;
    }
};