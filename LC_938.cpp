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
    int sum=0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL)
            return 0;
        traverse(root,L,R);
        return sum;
    }
    void traverse(TreeNode* root,int L,int R)
    {
        if(root==NULL)
            return;
        traverse(root->left,L,R);
        traverse(root->right,L,R);
         if((root->val>=L)&&(root->val<=R))
            sum=sum+root->val;
    }
};
