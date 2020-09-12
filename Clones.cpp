/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>& mp)
    {
        if(node == NULL)
            return NULL;
        if(mp.find(node) == mp.end())
        {
            mp[node] = new Node(node->val);
            for(Node* neigh: node->neighbors)
            {
                mp[node]->neighbors.push_back(dfs(neigh,mp));
            }
        }
        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
           return node;
        unordered_map<Node*,Node*>mp;
        return dfs(node,mp);
        /*Node* copy = new Node(node->val);
        mp[node]=copy;
          queue<Node*>q;
           q.push(node);
           int i;
           while(!q.empty())
           {
               Node* fron = q.front();
               q.pop();
               for(i=0;i<fron->neighbors.size();i++)
               {
                   Node* neigh = fron->neighbors[i];
                   if(mp.find(neigh)==mp.end())
                   {
                       mp[neigh] = new Node(neigh->val);
                       q.push(neigh);
                   }
                   mp[fron]->neighbors.push_back(mp[neigh]);
               }
           }
           return copy;*/
           }
};

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
    Node* cloneTree(Node* root) {
        if(root==NULL)
            return NULL;
        Node* copy = new Node(root->val);
        for(Node* neigh: root->children)
            copy->children.push_back(cloneTree(neigh));
        return copy;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* get(Node* temp)
    {
        if(temp == NULL)
            return NULL;
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        else
        {
            mp[temp] = new Node(temp->val);
            return mp[temp];
        }
    }
    unordered_map<Node*,Node*>mp;
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        if(mp.find(head)!=mp.end())
            return mp[head];
        mp[head]=new Node(head->val);
        mp[head]->next = copyRandomList(head->next);
        mp[head]->random = copyRandomList(head->random);
        return mp[head];
        // Node* temp = head;
        // Node* newnode = new Node(temp->val);
        // mp[temp]=newnode;
        // while(temp!=NULL)
        // {
        //     newnode->next = get(temp->next);
        //     newnode->random = get(temp->random);
        //     temp=temp->next;
        //     newnode=newnode->next;
        // }
        // return mp[head];
    }
};

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* dfs(Node* head,unordered_map<Node*,NodeCopy*>& mp)
    {
        if(head == NULL)
            return NULL;
        if(mp.find(head)!=mp.end())
            return mp[head];
        NodeCopy* copy = new NodeCopy(head->val);
        mp[head] = copy;
        copy->left = dfs(head->left,mp);
        copy->right = dfs(head->right,mp);
        copy->random = dfs(head->random,mp);
        return copy;
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*,NodeCopy*>mp;
        if(root == NULL)
            return NULL;
        return dfs(root,mp);
    }
};
