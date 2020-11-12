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
    TreeNode* deletenode(TreeNode* root,int target)
    {
        if(root==NULL)
            return NULL;
        root->left = deletenode(root->left,target);
        root->right = deletenode(root->right,target);
        if((root->left==NULL)&&(root->right==NULL)&&(root->val == target))
        {
            root=NULL;
            //return root;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        return deletenode(root,target);
        //return root;
    }
};
