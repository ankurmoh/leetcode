class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26]={0},i,len=s.length(),flag=0;
        for(i=0;i<len;i++)
            freq[s[i]-'a']++;
        len=t.length();
         for(i=0;i<len;i++)
            freq[t[i]-'a']--;
        for(i=0;i<26;i++)
            if(freq[i]!=0)
                return false;
        return true;
    }
};
