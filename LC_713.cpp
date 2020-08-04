class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0,left=0,right=0,n=nums.size(),prod=1;
        if(k<=1)
            return 0;
        for(right=0;right<n;right++)
        {
            prod=prod*nums[right];
            while(prod>=k)
            {
                prod=prod/nums[left];
                left++;
            }
            ans=ans+(right-left+1);
        }
        return ans;
    }
};
