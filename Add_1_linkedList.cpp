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
    ListNode* plusOne(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* node=head;
        ListNode* start=NULL;
        while(node)
        {
            if(node->val<9)
                start=node;
            node=node->next;
        }
        if(start)
        {
            start->val=start->val+1;
            node=start->next;
        }
        else if(!start)
        {
            ListNode* n = new ListNode(1);
            n->next=head;
            head=n;
            node=head->next;
            //head=n;
        }
        while(node)
        {
            node->val=0;
            node=node->next;
        }
        return head;
    }
};
