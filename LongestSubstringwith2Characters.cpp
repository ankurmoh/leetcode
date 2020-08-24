class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
       unordered_map<char,int>position;
        int left=0,right=0,len=s.length(),maxlen=2,minindex;
        char minval;
        if(len<=2)
            return len;
        while(right<len)
        {
            if(position.size()<3)
            {
                position[s[right]]=right;
                right++;
            }
            if(position.size()==3)
            {
                minindex=INT_MAX;
                for(auto it=position.begin();it!=position.end();it++)
                {
                    if(it->second<minindex)
                    {
                        minindex=it->second;
                        minval=it->first;
                    }
                }
                left=minindex+1;
                position.erase(minval);
            }
            maxlen=max(maxlen,(right-left));
        }
        return maxlen;
    }
};
