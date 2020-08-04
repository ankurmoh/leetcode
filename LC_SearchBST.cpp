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
    TreeNode* searchBST(TreeNode* root, int val) {
        if ((root==NULL) || (root->val == val))
            return root;
       /* else if(root->val > val)
            return searchBST(root->left,val);
        else if(root->val < val)
            return searchBST(root->right,val);
        return NULL; */
        while(root!=NULL)
        {
            if(root->val>val)
                root=root->left;
            else if(root->val<val)
                root=root->right;
            else if(root->val==val)
                return root;
        }
        return NULL;
    }
};
