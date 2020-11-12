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
    unordered_map<int,int>mp;
    int find(vector<int>& arr,int l,int r,int tar)
    {
        for(int i=l;i<=r;i++)
        {
            if(arr[i]==tar)
                return i;
        }
        return -1;
    }
    TreeNode* construct(int prestart, int preend, int poststart, int postend, vector<int>& pre, vector<int>& post)
    {
        if((prestart>preend) || (poststart>postend))
            return NULL;
        if(prestart == preend)
        {
            return new TreeNode(pre[prestart]);
        }
        TreeNode* root = new TreeNode(pre[prestart]);
        int leftroot_pre = prestart+1;
        //int leftroot_post = find(post,poststart,postend,pre[leftroot_pre]);
        int leftroot_post = mp[pre[leftroot_pre]];
        int L = leftroot_post - poststart + 1;
        int leftend_pre = leftroot_pre + L - 1;
        root->left = construct(leftroot_pre, leftend_pre, poststart, leftroot_post, pre, post);
        root->right = construct(leftend_pre+1, preend, leftroot_post+1, postend-1, pre, post);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if((pre.size() == 0) || (post.size() == 0) || (pre.size() != post.size()))
            return NULL;
        for(int i=0;i<post.size();i++)
            mp[post[i]]=i;
        return construct(0, pre.size()-1, 0, post.size()-1, pre, post);
    }
};
