class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>mp(1010, 0);
        int i,sz=target.size();
        for(i=0;i<sz;i++)
        {
            mp[target[i]]++;
            mp[arr[i]]--;
        }
        bool x;
        for(i=0;i<1010;i++)
        {
            if(mp[i]!=0)
                return false;
        }
        return true;
    }
};
