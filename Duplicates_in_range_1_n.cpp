class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i,sz=nums.size(),ind;
        vector<int>res;
        if(sz==0)
            return res;
        for(i=0;i<sz;i++)
        {
            ind = abs(nums[i])-1;
            if(nums[ind]>0)
                nums[ind] = -nums[ind];
        }
        for(i=1;i<=sz;i++)
        {
            if(nums[i-1]>0)
                res.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i,sz=nums.size(),ind;
        vector<int>res;
        if(sz==0)
            return res;
        for(i=0;i<sz;i++)
        {
            ind = abs(nums[i])-1;
            nums[ind] = -nums[ind];
        }
        for(i=0;i<sz;i++)
        {
            ind = abs(nums[i])-1;
            if(nums[ind]>0)
            {
                res.push_back(abs(nums[i]));
                nums[ind]=-nums[ind];
            }
        }
        return res;
    }
};
