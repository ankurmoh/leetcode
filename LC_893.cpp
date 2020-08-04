class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        string odd,even;
        unordered_map<string,int>mp;
        int i,len=A.size(),j,len1;
        for(i=0;i<len;i++)
        {
            odd="";
            even="";
            len1=A[i].length();
            for(j=0;j<len1;j++)
            {
                if(j%2)
                    odd=odd+A[i][j];
                else
                    even=even+A[i][j];
            }
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
            mp[odd+even]++;
        }
        return mp.size();
    }
};
