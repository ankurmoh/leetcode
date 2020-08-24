class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>s(deadends.begin(),deadends.end());
        if(s.count("0000"))
            return -1;
        unordered_map<string,bool>visited;
        if(target=="0000")
            return 0;
        int con=0,i,j,c=0,val1,k,val2;
        string temp,temp1,temp2;
        char ch;
        queue<string>q;
        q.push("0000");
        visited["0000"]=true;
        while(!q.empty())
        {
            con=q.size();
            for(i=0;i<con;i++)
            {
                temp=q.front();
                q.pop();
                if(temp==target)
                    return c;
                for(j=0;j<4;j++)
                {
                  ch=temp[j];
                  if(ch=='9')
                      val1=0;
                    else
                        val1 = 1+ (ch-'0');
                    if(ch=='0')
                        val2=9;
                    else
                        val2=(ch-'0')-1;
                    temp1=temp.substr(0,j) + char(val1+'0') + temp.substr(j+1);
                    temp2=temp.substr(0,j) + char(val2+'0') + temp.substr(j+1);
                    if((!s.count(temp1)) && (visited.find(temp1)==visited.end()))
                    {
                        q.push(temp1);
                        visited[temp1]=true;
                    }
                    if((!s.count(temp2)) && (visited.find(temp2)==visited.end()))
                    {
                        q.push(temp2);
                        visited[temp2]=true;
                    }
                }
            }
            c++;
        }
        return -1;
    }
};
