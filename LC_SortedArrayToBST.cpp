/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        return sortBST(nums,left,right);
    }

    TreeNode* sortBST(vector<int>& nums,int left, int right)
    {
        if(left>right)
            return NULL;
        int mid = left + (right-left)/2;
        TreeNode *root= new TreeNode(nums[mid]);
        root->left = sortBST(nums,left,mid-1);
        root->right= sortBST(nums,mid+1,right);
        return root;
    }
};
