/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxdia=0;
    int diameter(Node* root) {
        depth(root);
        return maxdia;
    }
    int depth(Node* root)
    {
        if(root==NULL)
            return 0;
        int max1=0,max2=0;
        int i,sz=root->children.size();
        for(i=0;i<sz;i++)
        {
            int ht = depth(root->children[i]);
            if(ht>=max1)
            {
                max2=max1;
                max1=ht;
            }
            else if((ht<max1) && (ht>=max2))
                max2=ht;
        }
        maxdia=max(maxdia,max1+max2);
        return 1+max1;
    }
};
