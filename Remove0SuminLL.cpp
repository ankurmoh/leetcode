/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL)
            return NULL;
        unordered_map<int,ListNode*>mp;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        int sum=0;
        while(head!=NULL)
        {
            sum=sum+head->val;
            mp[sum]=head;
            head=head->next;
        }
        head = dummy;
        sum=0;
        while(head!=NULL)
        {
            sum=sum+head->val;
            ListNode* next = mp[sum];
            if(next!=head)
            {
                head->next = next->next;
            }
            head=head->next;
        }

         return dummy->next;
    }
};
