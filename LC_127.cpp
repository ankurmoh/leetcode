class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        string temp;
        int i,len,jump=1,sz,j,k;
        char c;
        while(!q.empty())
        {
            sz=q.size();
            for(i=0;i<sz;i++)
            {
                temp=q.front();
                q.pop();
                if(temp==endWord)
                    return jump;
                s.erase(temp);
                len=temp.length();
                for(j=0;j<len;j++)
                {
                    c=temp[j];
                    for(k=0;k<26;k++)
                    {
                        temp[j]='a' + k;
                        if(temp[j]==c)
                            continue;
                        if(s.count(temp))
                            q.push(temp);
                    }
                    temp[j]=c;
                }
            }
            jump++;
        }
        return 0;
    }
};
