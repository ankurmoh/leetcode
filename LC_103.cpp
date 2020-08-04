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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<TreeNode*>q;
        int i,count,iter=0;
        q.push(root);
        while(!q.empty())
        {
        count=q.size();
        vector<int>v;
            iter++;
        for(i=0;i<count;i++)
        {
            TreeNode *x=q.front();
            q.pop();
            v.push_back(x->val);
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }
            if(iter%2==0)
                reverse(v.begin(),v.end());
             res.push_back(v);
        }
        return res;
    }
};
