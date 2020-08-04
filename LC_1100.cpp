class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int i,len=S.length(),j,con=0;
        if(len<K)
            return con;
        unordered_map<char,int>mp;
        for(i=0;i<K;i++)
            mp[S[i]]++;
        if(mp.size()==K)
            con++;
        for(i=K;i<len;i++)
        {
            mp[S[i-K]]--;
            if(mp[S[i-K]]==0)
                mp.erase(S[i-K]);
            mp[S[i]]++;
            if(mp.size()==K)
                con++;
        }
        return con;
    }
};
