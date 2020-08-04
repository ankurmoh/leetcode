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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> >v;
        if(root==NULL)
            return v;
        queue<Node*>q;
        int n,sz,i;
        q.push(root);
        while(!q.empty())
        {
            n=q.size();
            vector<int>temp;
            while(n>0)
            {
                Node *x=q.front();
                q.pop();
                temp.push_back(x->val);
                sz=x->children.size();
                for(i=0;i<sz;i++)
                    q.push(x->children[i]);
                n--;
            }
            v.push_back(temp);
        }
        return v;
    }
};
