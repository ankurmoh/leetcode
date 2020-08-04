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
    unordered_map<TreeNode*,vector<TreeNode*>>graph;
    vector<int>ans;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if((root==NULL) || (K<0) || (target==NULL))
            return ans;
        if((K==0) && (target!=NULL))
        {
            ans.push_back(target->val);
            return ans;
        }
        buildgraph(root,NULL);
        if(graph.find(target)==graph.end())
            return ans;
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        int count,size,i;
        while(!q.empty())
        {
            count=q.size();
            if(K==0)
            {
                for(i=0;i<count;i++)
                {
                    TreeNode *y=q.front();
                    q.pop();
                    ans.push_back(y->val);
                }
                return ans;
            }
            while(count>0)
            {
                TreeNode *x=q.front();
                q.pop();
                size=graph[x].size();
                for(i=0;i<size;i++)
                {
                    TreeNode *y=graph[x][i];
                    if(visited.find(y)==visited.end())
                    {
                        visited[y]=true;
                        q.push(y);
                    }
                }
                count--;
            }
            K--;
        }
        return ans;
    }
    void buildgraph(TreeNode* root, TreeNode* parent)
    {
        if(root==NULL)
            return;
        if(graph.find(root)==graph.end())
        {
            if(parent!=NULL)
            {
                graph[root].push_back(parent);
                graph[parent].push_back(root);
            }
            buildgraph(root->left,root);
            buildgraph(root->right,root);
        }
        return;
    }
};
