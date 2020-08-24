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
    ListNode* sortList(ListNode* head) {
       if((head==NULL) || (head->next==NULL))
           return head;
        mergesort(&head);
        return head;
    }
    void mergesort(ListNode** head)
    {
        ListNode *h1= *head;
        if((h1==NULL) || (h1->next==NULL))
           return;
        ListNode *a, *b;
        split(h1,&a,&b);
        mergesort(&a);
        mergesort(&b);
        *head=merge(a,b);
    }
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode *result;
        if(a==NULL)
            return b;
        else if(b==NULL)
            return a;
        if(a->val<=b->val)
        {
            result=a;
            result->next=merge(a->next,b);
        }
        else
        {
           result=b;
           result->next=merge(a,b->next);
        }
        return result;
    }
    void split(ListNode* head, ListNode** a, ListNode** b)
    {
        ListNode *slow=head, *fast=head->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        *a=head;
        *b=slow->next;
        slow->next=NULL;
    }
};
