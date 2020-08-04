class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int i,len=nums.size();
        for(i=1;i<len;i++)
            nums[i]=nums[i]+nums[i-1];
        return nums;
    }
};
