/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct compare
    {
        bool operator() (const ListNode* l, const ListNode* r)
        {
            return l->val>r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        int i,sz=lists.size();
        for(i=0;i<sz;i++)
        {
            if(lists[i])
                pq.push(lists[i]);
        }
        if(pq.empty())
            return NULL;
        ListNode* current=pq.top();
        pq.pop();
        if(current->next)
            pq.push(current->next);
        ListNode* ans=current;
        while(!pq.empty())
        {
            current->next=pq.top();
            pq.pop();
            current=current->next;
            if(current->next)
                pq.push(current->next);
        }
        return ans;
    }
};
