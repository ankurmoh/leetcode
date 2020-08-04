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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        queue< TreeNode* >q;
        int count,i;
        //map<int, vector<int> >mp;
        if(root==NULL)
            return v;
        q.push(root);
        while(!q.empty())
        {
            count=q.size();
            vector<int>temp;
            while(count>0)
            {
                TreeNode *x=q.front();
                q.pop();
                temp.push_back(x->val);
               // mp[depth].push_back(x->val);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                count--;
            }
            v.push_back(temp);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
