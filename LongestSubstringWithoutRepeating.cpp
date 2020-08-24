class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,len=s.length(),maxlen=0;
        unordered_set<char>st;
        i=0;j=0;
        for(i=0;i<len;i++)
        {
            while(st.count(s[i]))
            {
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            maxlen=max(maxlen,i-j+1);
        }
        return maxlen;
    }
};
