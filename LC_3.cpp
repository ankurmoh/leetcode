class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=1,len=s.length(),maxlen=1;
        if (len ==0)
            return 0;
        set<char>st;
        st.insert(s[0]);
        while(right<len)
        {
            while((st.count(s[right])) && (left<len))
            {
                maxlen=max(maxlen,right-left);
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            right++;
        }
        return max(maxlen,right-left);
    }
};
