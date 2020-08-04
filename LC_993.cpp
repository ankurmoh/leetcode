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
    queue< pair < TreeNode*, pair< TreeNode*, int > > >q;

    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,TreeNode*>parent;
        unordered_map<int,int>level;
        int depth,count;
        TreeNode *prev=NULL;
        TreeNode *current=NULL;
        if(root==NULL)
            return false;

        q.push(make_pair(prev , make_pair(root,0)));
        while(!q.empty())
        {
            count=q.size();
            while(count>0)
            {
                current=q.front().second.first;
                depth=q.front().second.second;
                prev=q.front().first;
                q.pop();
                level[current->val]=depth;
                parent[current->val]=prev;
                if(current->left)
                    q.push(make_pair(current, make_pair(current->left,depth+1)));
                if(current->right)
                    q.push(make_pair(current, make_pair(current->right,depth+1)));
                count--;
            }
        }
        if ((parent[x]!=parent[y]) && (level[x]==level[y]))
            return true;
        return false;
    }
};
