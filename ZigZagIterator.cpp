class ZigzagIterator {
public:
    int p1=0,p2=0,flag=0;
    vector<int>v3,v4;
    queue<vector<int>>q;
    vector<vector<int>>matrix;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v3=v1;
        v4=v2;
        if(v1.size()>0)
        {
         q.push({v1[0],0,0});
        }
        matrix.push_back(v1);
        if(v2.size()>0)
        {
        q.push({v2[0],1,0});
        }
        matrix.push_back(v2);
    }

    int next() {
        int ans,oldrow,newcol;
        vector<int>fron = q.front();
        q.pop();
        ans = fron[0];
        oldrow = fron[1];
        newcol = fron[2]+1;
        if(newcol<matrix[oldrow].size())
            q.push({matrix[oldrow][newcol],oldrow,newcol});
        // if((flag == 0) && (p1<v3.size()))
        // {
        //     flag=1;
        //     ans = v3[p1];
        //     p1++;
        // }
        // else if((flag == 1) && (p2<v4.size()))
        // {
        //     flag=0;
        //     ans=v4[p2];
        //     p2++;
        // }
        // else if(p1<v3.size())
        // {
        //     ans = v3[p1];
        //     p1++;
        // }
        // else
        // {
        //     ans = v4[p2];
        //     p2++;
        // }
         return ans;
    }

    bool hasNext() {
        // if((p1 >= v3.size()) && (p2 >= v4.size()))
        //     return false;
        // return true;
        if(q.empty())
            return false;
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
