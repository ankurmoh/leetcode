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
    Node* findRoot(vector<Node*> tree) {
        // unordered_map<Node*,int>mp;
        // int i,len=tree.size(),j;
        // for(i=0;i<len;i++)
        // {
        //     Node* parent=tree[i];
        //     for(j=0;j<parent->children.size();j++)
        //         mp[parent->children[j]]=1;
        // }
        // for(i=0;i<len;i++)
        // {
        //     if(mp.find(tree[i])==mp.end())
        //         return tree[i];
        // }
        // return NULL;
        int i,len=tree.size(),sum1=0,sum2=0,j;
        for(i=0;i<len;i++)
        {
            Node* parent=tree[i];
            sum1=sum1+parent->val;
            sum2=sum2+parent->val;
            for(j=0;j<parent->children.size();j++)
                sum2=sum2+parent->children[j]->val;
        }
        sum2=2*sum1-sum2;
        for(i=0;i<len;i++)
        {
            if(tree[i]->val==sum2)
                return tree[i];
        }
        return NULL;
    }
};
