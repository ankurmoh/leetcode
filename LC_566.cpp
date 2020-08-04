class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>>res(r);
        int i,j,m=nums.size(),n=nums[0].size(),con=0,cur=0;
        if(m*n != r*c)
            return nums;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if (con < c)
                {
                res[cur].push_back(nums[i][j]);
                con++;
                }
                if (con == c)
                {
                    cur++;
                    con=0;
                }
            }
        }
        return res;
    }
};
