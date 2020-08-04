class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int i,j,len=nums.size(),maxassign=-1;
        vector<int>res(len,0);
        for(i=0;i<len;i++)
        {
            for(j=len-1;j>=index[i];j--)
            {
               if(j>=1)
                   res[j]=res[j-1];
            }
              //  res[j]=res[j-1];
            res[index[i]]=nums[i];
        }
        return res;
    }
};
