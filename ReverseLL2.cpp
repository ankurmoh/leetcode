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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if((head == NULL) || (head->next == NULL) || (m==n) || (m<0) || (n<0))
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev = dummy;
        ListNode* current = head;
        int i;
        for(i=1;i<m;i++)
        {
            prev = current;
            current = current->next;
        }
        ListNode* node = prev;
        ListNode* next=NULL;
        for(i=m;i<=n;i++)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        node->next->next = current;
        node->next = prev;
        return dummy->next;
    }
};
