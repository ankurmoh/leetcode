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
    vector<int> preorder(Node* root) {
        stack<Node*>s;
        vector<int>v;
        if(root==NULL)
            return v;
        s.push(root);
        int sz,i;
        while(!s.empty())
        {
            Node *x=s.top();
            s.pop();
            v.push_back(x->val);
            auto it = x->children.end();
            while(it!=x->children.begin())
            {
                it--;
                s.push(*it);
            }
           /* sz=x->children.size();
            for(i=sz-1;i>=0;i--)
                s.push(x->children[i]); */
        }
        return v;
    }
};
