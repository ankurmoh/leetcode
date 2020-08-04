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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *h1=l1, *h2=l2;
        ListNode *sentinel=new ListNode(0);
        ListNode *current=sentinel;
        int count=0;
        while(h1 || h2)
        {
           if(h1 && h2)
           {
           if(h1->val<=h2->val)
           {
              current->next=new ListNode(h1->val);
               h1=h1->next;
           }
               else
               {
                   current->next=new ListNode(h2->val);
                   h2=h2->next;
               }
            }
            else
            {
                if(h1 && !h2)
            {
               current->next=new ListNode(h1->val);
               h1=h1->next;
            }
            else if(!h1 && h2)
            {
                current->next=new ListNode(h2->val);
               h2=h2->next;
            }
            }
            current=current->next;
        }
        return sentinel->next;
    }
};
