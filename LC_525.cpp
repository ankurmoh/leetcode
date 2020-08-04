class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int sum=0,i;
       unordered_map<int,int> m;
       int longest = 0;

        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                sum=sum-1;
            else
                sum=sum+1;

           auto it = m.find(sum);

           if(sum == 0)
           {
              if(longest < i+1)
               longest = i+1;
           }
           if(it != m.end())
           {
              if(longest < i-it->second)
               longest = i-it->second;
           }
            m.insert({sum,i});
       }
        return longest;
    }
};
