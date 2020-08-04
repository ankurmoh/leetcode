class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int i,j,sum=0,len=nums.size();
        left-=1;
        right-=1;
        vector<int>res;
        for(i=0;i<len;i++)
        {
            sum=nums[i];
            res.push_back(sum);
            for(j=i+1;j<len;j++)
            {
                sum=(sum+nums[j])%1000000007;
                res.push_back(sum);
            }
        }
        sort(res.begin(),res.end());
        sum=0;
        for(i=left;i<=right;i++)
            sum=(sum+res[i])%1000000007;
        return sum;
    }
};
