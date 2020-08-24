queue<NestedInteger>q;
        int i,sz=nestedList.size(),level=1,j,sum=0;
        NestedInteger fron;
        for(i=0;i<sz;i++)
            q.push(nestedList[i]);
        while(!q.empty())
        {
            sz = q.size();
            for(i=0;i<sz;i++)
            {
                fron = q.front();
                q.pop();
                if(fron.isInteger())
                    sum = sum + fron.getInteger()*level;
                else
                {
                    vector<NestedInteger>list = fron.getList();
                    for(j=0;j<list.size();j++)
                    {
                        q.push(list[j]);
                    }
                }
            }
            level++;
        }
        return sum;
