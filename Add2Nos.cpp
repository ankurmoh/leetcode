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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;
        stack<int>s2;
        ListNode* x=l1;
        int sum,carry=0;
        while(x)
        {
            s1.push(x->val);
            x=x->next;
        }
        x=l2;
        while(x)
        {
            s2.push(x->val);
            x=x->next;
        }
        ListNode* val=NULL;
        while(!s1.empty() || !s2.empty() || carry!=0)
        {
            sum=0;
            if(!s1.empty())
            {
                sum=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum=sum+s2.top();
                s2.pop();
            }
            sum=sum+carry;
            ListNode* dummy=new ListNode(sum%10);
            dummy->next=val;
            val=dummy;
            carry=sum/10;
        }
        return val;
    }
};
