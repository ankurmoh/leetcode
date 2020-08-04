class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,len=nums.size(),currentsum,maxsum;
        currentsum=nums[0];
        maxsum=nums[0];
        for(i=1;i<len;i++)
        {
            currentsum=max(nums[i],currentsum+nums[i]);
            maxsum=max(maxsum,currentsum);
        }
        return maxsum;
    }
};
