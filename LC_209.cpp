class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i,sz=nums.size(),pos=0,sum=0,mini = INT_MAX;
       for(i=0;i<sz;i++)
       {
           sum=sum+nums[i];
           while(sum>=s)
           {
               mini=min(mini,i-pos+1);
               sum=sum-nums[pos];
               pos++;
           }
       }
        if(mini==INT_MAX)
            return 0;
        return mini;
    }
};
