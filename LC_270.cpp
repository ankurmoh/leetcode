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
    int closestValue(TreeNode* root, double target) {
        if(root==NULL)
            return 0;
        if((!root->left)&&(!root->right))
            return root->val;
        double res,mini=DBL_MAX;
        int ans;
        while(root!=NULL)
        {
            res=abs(target-root->val);
            if(res<mini)
            {
                mini=res;
                ans=root->val;
            }
            if(root->val>target)
                root=root->left;
            else if(root->val<=target)
                root=root->right;
        }
        return ans;
    }
};
