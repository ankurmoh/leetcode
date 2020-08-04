class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>s(bank.begin(),bank.end());
        int jump=1,sz,j,len,i,k;
        s.insert(start);
        vector<char>pos = {'A','C','G','T'};
        queue<string>q;
        q.push(start);
        string fron;
        char ch;
        while(!q.empty())
        {
            sz=q.size();
            for(i=0;i<sz;i++)
            {
                fron=q.front();
                q.pop();

                len=fron.length();
                s.erase(fron);
                for(j=0;j<len;j++)
                {
                    ch=fron[j];
                    for(k=0;k<4;k++)
                    {
                        if(pos[k]==ch)
                            continue;
                        fron[j]=pos[k];
                        if(s.count(fron))
                        {
                            q.push(fron);
                            if(fron==end)
                                 return jump;
                        }
                    }
                    fron[j]=ch;
                }
            }
            jump++;
        }
        return -1;
    }
};
