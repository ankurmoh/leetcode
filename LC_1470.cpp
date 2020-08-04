class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i,j;
        vector<int>res;
        for(i=0,j=n;i<n,j<2*n;i++,j++)
        {
            res.push_back(nums[i]);
            res.push_back(nums[j]);
        }
        return res;
    }
};
