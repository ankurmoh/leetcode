class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int>st(G.begin(),G.end());
        int con=0;
        ListNode* current = head;
        while(current!=NULL)
        {
            if((st.count(current->val)) && ((current->next == NULL) || (!st.count(current->next->val))))
                con++;
            current=current->next;
        }
        return con;
    }
};
