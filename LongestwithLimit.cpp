class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int right=1,left=0,maxsz=1,sz=nums.size(),maxi,mini;
        multiset<int>s;
        s.insert(nums[0]);
        while(right<sz)
        {
            s.insert(nums[right]);
            maxi = *s.rbegin();
            mini = *s.begin();
            while(maxi-mini > limit)
            {
                s.erase(s.find(nums[left]));
                left++;
                maxi = *s.rbegin();
                mini = *s.begin();
            }
            maxsz=max(maxsz,right-left+1);
            cout<<right-left+1<<" ";
            right++;
        }
        return maxsz;
    }
};
