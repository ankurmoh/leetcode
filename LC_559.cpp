/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        /*int depth=0;
        for(auto it=root->children.begin();it!=root->children.end();it++)
            depth=max(depth,maxDepth(*it));

        return depth+1;*/
        queue<Node*>q;
        q.push(root);
        int depth=0,con,i,sz,j;
        while(!q.empty())
        {
            con = q.size();
            for(i=0;i<con;i++)
            {
                Node* fron = q.front();
                q.pop();
                sz = fron->children.size();
                for(j=0;j<sz;j++)
                    q.push(fron->children[j]);
            }
            depth++;
        }
        return depth;
    }
};
