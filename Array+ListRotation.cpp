class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>copy=nums;
        int i,sz=nums.size();
        for(i=0;i<sz;i++)
            copy[(i+k)%sz]=nums[i];
        nums=copy;
    }
};

void rotate(vector<int>& nums, int k) {
    int sz=nums.size();
    k=k%sz;
    reverse(nums.begin(),nums.end()-k);
    reverse(nums.end()-k,nums.end());
    reverse(nums.begin(),nums.end());
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if((head==NULL) || (head->next==NULL))
            return head;
        if(k==0)
            return head;
        int len=1,con,i;
        ListNode *x=head , *h1;
        while(x->next!=NULL)
        {
            x=x->next;
            len++;
        }
        x->next=head;
        k=k%len;
        for(i=0;i<len-k;i++)
            x=x->next;
        h1=x->next;
        x->next=NULL;
        return h1;
    }
};
