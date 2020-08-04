class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        unordered_map<int,int>mp;
        int i,len=nums.size(),con=4;
        if (len == 0)
            return vector<string>();
        for(i=0;i<len;i++)
            mp[nums[i]]=i;
        vector<int>temp = nums;
        sort(temp.rbegin(),temp.rend());
        vector<string>res(len);
        res[mp[temp[0]]]="Gold Medal";
        if(len == 1)
            return res;
        res[mp[temp[1]]]="Silver Medal";
        if(len == 2)
            return res;
        res[mp[temp[2]]]="Bronze Medal";
        for(i=3;i<len;i++)
        {
            res[mp[temp[i]]]=to_string(con);
            con++;
        }
        return res;
    }
};
