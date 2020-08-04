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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<pair<TreeNode*,int>>q;
        unordered_map<int,vector<int>>mp;
        int i,sz,weight,minw=INT_MAX,maxw=INT_MIN;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            TreeNode *x=q.front().first;
            weight=q.front().second;
            q.pop();
            mp[weight].push_back(x->val);
            if(x->left)
                q.push(make_pair(x->left,weight-1));
            if(x->right)
                q.push(make_pair(x->right,weight+1));
            minw=min(minw,weight);
            maxw=max(maxw,weight);
        }
        for(i=minw;i<=maxw;i++)
        {
            if(mp.find(i)!=mp.end())
                res.push_back(mp[i]);
        }
        return res;
    }
};
