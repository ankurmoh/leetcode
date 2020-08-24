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
    TreeNode* inordersucc(TreeNode* x)
    {
        while(x->left!=NULL)
            x=x->left;
        return x;
    }
    TreeNode* inorderpred(TreeNode* x)
    {
        while(x->right!=NULL)
            x=x->right;
        return x;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(key>root->val)
            root->right = deleteNode(root->right, key);
        else if(key<root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            if((root->left==NULL) && (root->right==NULL))
                root=NULL;
            else if(root->right!=NULL)
            {
                TreeNode* x = inordersucc(root->right);
                root->val = x->val;
                root->right = deleteNode(root->right, root->val);
            }
            else if(root->left!=NULL)
            {
                TreeNode* x = inorderpred(root->left);
                root->val = x->val;
                root->left=deleteNode(root->left,root->val);
            }
        }
        return root;
    }
};
