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
    unordered_map<TreeNode*,int>d;
    int depth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(d.find(root)!=d.end())
            return d[root];
        d[root] = 1 + max(depth(root->left), depth(root->right));
        //return 1 + max(depth(root->left), depth(root->right));
        return d[root];
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL)
            return root;
        depth(root);
        for(auto it = d.begin();it!=d.end();it++)
        {
            cout<<it->first->val<<" "<<it->second<<endl;
        }
        int left = root->left == NULL ? 0: d[root->left];
        int right = root->right == NULL ? 0 : d[root->right];
        while(left!=right)
        {
            if(left>right)
            {
                root=root->left;
                //left = root->left == NULL ? 0: d[root->left];
            }
            else
            {
                root=root->right;
                //right = root->right == NULL ? 0 : d[root->right];
            }
            left = root->left == NULL ? 0: d[root->left];
            right = root->right == NULL ? 0 : d[root->right];
        }
        return root;
        // if(left == right)
        //     return root;
        // if(left>right)
        //     return lcaDeepestLeaves(root->left);
        // return lcaDeepestLeaves(root->right);
    }
};
