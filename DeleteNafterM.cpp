class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if(head == NULL)
            return NULL;
        ListNode* current=head;
        ListNode* prev = NULL;
        int con1=0,con2=0;
        while(current!=NULL)
        {
            con1=0;con2=0;
            while((con1<m) && (current!=NULL))
            {
                prev=current;
                current=current->next;
                con1++;
            }
            while((con2<n) && (current!=NULL))
            {
                current=current->next;
                con2++;
            }
            prev->next = current;
        }
        return head;
    }
};
