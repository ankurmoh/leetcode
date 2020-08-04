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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        vector<int>temp;
        int count;
        if(root==NULL)
            return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            count=q.size();
            temp.clear();
            while(count>0)
            {
                TreeNode *x=q.front();
                q.pop();
                temp.push_back(x->val);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                count--;
            }
            v.push_back(temp);
        }
        return v;
    }
};
