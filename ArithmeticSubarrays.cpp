class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int i,n=l.size(),start,end,small,ssmall,d,con,to_find,flag,j;
        vector<bool>res;
        for(i=0;i<n;i++)
        {
            start = l[i];
            end = r[i];
            if(end-start<=1)
            {
                res.push_back(true);
                continue;
            }
            flag = 0;
            small=INT_MAX;
            ssmall=INT_MAX;
            unordered_map<int,int>freq;
            for(j=start;j<=end;j++)
            {
                freq[nums[j]]++;
                if(nums[j]<small)
                {
                    ssmall = small;
                    small = nums[j];
                }
                else if((nums[j]>small)&&(nums[j]<ssmall))
                    ssmall = nums[j];
            }
            //cout<<small<<" "<<ssmall<<endl;
            if(ssmall == INT_MAX)
            {
                res.push_back(true);
                continue;
            }
            d = ssmall-small;
            con = end-start-1;
            to_find = d+ssmall;
            while(con>0)
            {
               if(freq.find(to_find) == freq.end())
               {
                   flag = 1;
                   break;
               }
                to_find = to_find + d;
                con--;
            }
            if(flag == 1)
                res.push_back(false);
            else
                res.push_back(true);
            //freq.clear();
        }
        return res;
    }
};
