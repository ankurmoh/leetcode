class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>>mp;
        int i,n=pieces.size(),j,con=0;
        for(i=0;i<n;i++)
        {
            mp[pieces[i][0]] = pieces[i];
            con=con + pieces[i].size();
        }
        n = arr.size();
        if(n!=con)
            return false;
        i=0;
        while(i<n)
        {
            if(mp.find(arr[i]) == mp.end())
                return false;
            con = mp[arr[i]].size();
            j=0;
            vector<int>temp = mp[arr[i]];
            while((j<con) && (i<n))
            {
                cout<<j<<" "<<i<<endl;
                if(arr[i]!=temp[j])
                    return false;
                j++;
                i++;
            }
        }
        return true;
    }
};
