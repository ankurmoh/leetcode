class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int>position;
        int i,sz=nums.size(),cursum=0,maxi=INT_MIN;
        for(i=0;i<sz;i++)
        {
            cursum=cursum+nums[i];
            if(cursum==k)
                maxi=max(maxi,i+1);
            if((position.find(cursum-k)!=position.end()))
                maxi=max(maxi, i - position[cursum-k]);
            if(position.find(cursum)==position.end())
                position[cursum]=i;
        }
        return max(maxi,0);
    }
};
