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
    ListNode* deleteDuplicates(ListNode* head) {
        if((head == NULL) || (head->next == NULL))
            return head;
        ListNode* sentinel = new ListNode(0);
        ListNode* prev = sentinel;
        sentinel->next = head;
        ListNode* current = head;
        while(current!=NULL)
        {
            while((current->next) && (current->val == current->next->val))
                current = current->next;
            if (prev->next == current)
            {
                prev = current;
                current=current->next;
            }
            else
            {
                prev->next = current->next;
                current=current->next;
            }
        }
        return sentinel->next;
    }
};
