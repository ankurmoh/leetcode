class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int i,len=nums.size(),mini=INT_MAX,sum=0;
        for(i=0;i<len;i++)
        {
            sum=sum+nums[i];
            mini=min(mini,sum);
        }
        if (mini>=0)
            return 1;
        return abs(mini) + 1;
    }
};
