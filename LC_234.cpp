class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2)
    {
        int i,sz=words.size(),mindiff=INT_MAX,j,sz1,pos1=-1,pos2=-1;
        for(i=0;i<sz;i++)
        {
            if(words[i]==word1)
                pos1=i;
            else if(words[i]==word2)
                pos2=i;
            if((pos1>=0)&&(pos2>=0))
                mindiff=min(mindiff,abs(pos1-pos2));
        }

        return mindiff;
    }
};
