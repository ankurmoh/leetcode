class Solution {
public:
    int countBinarySubstrings(string s) {
        int i=0,len=s.length(),j,con;
        char current;
        vector<int>group;
        while(i<len)
        {
            current = s[i];
            con=1;
            j=i+1;
            while((j<len) && (s[j]==current))
            {
                con++;
                j++;
            }
            group.push_back(con);
            i=j;
        }
        len=group.size();
        con=0;
        for(i=0;i<len-1;i++)
        {
            con=con + min(group[i],group[i+1]);
        }
        return con;
    }
};
