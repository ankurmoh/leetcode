class Solution {
public:
    int rob(vector<int>& nums) {
        int i,len=nums.size(),flag=0;
        if(len==0)
            return 0;
        if(len==1)
            return nums[0];
        vector<int>memo(len);
        memo[0]=nums[0];
        memo[1]=max(nums[0],nums[1]);
        for(i=2;i<len;i++)
            memo[i]=max(nums[i]+memo[i-2],memo[i-1]);
        return memo[len-1];
    }
};
