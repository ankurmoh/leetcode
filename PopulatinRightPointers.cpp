/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(root==NULL)
            return root;
        Node *lastnode=root;
        q.push(root);
        while(!q.empty())
        {
            Node *x=q.front();
            q.pop();
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
            if(x==lastnode)
            {
                x->next=NULL;
                lastnode=q.back();
            }
            else
                x->next=q.front();
        }
        return root;
    }
};
