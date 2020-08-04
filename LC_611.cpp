class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int sz=nums.size(),i,j,k,con=0;
        if(sz==0)
            return 0;
        sort(nums.begin(),nums.end());
        for(k=sz-1;k>=2;k--)
        {
            i=0;
            j=k-1;
            while(i<j)
            {
                if(nums[i]+nums[j]>nums[k])
                {
                    con=con + j-i;
                    j--;
                }
                else if(nums[i]+nums[j]<=nums[k])
                    i++;
            }
        }
        return con;
    }
};
