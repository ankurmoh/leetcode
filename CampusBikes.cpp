class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>> >, greater< pair< int, pair<int,int> > > >pq;
        int i,wor = workers.size(), bik = bikes.size(),j,x,y,dist;
        vector<int>visited(wor,-1);
        for(i=0;i<wor;i++)
        {
            x = workers[i][0];
            y = workers[i][1];
            for(j=0;j<bik;j++)
            {
                dist = abs(x-bikes[j][0]) + abs(y-bikes[j][1]);
                pq.push(make_pair(dist,make_pair(i,j)));
            }
        }

        unordered_set<int>assigned;
        while(!pq.empty())
        {
            pair<int, pair<int,int> >fron = pq.top();
            pq.pop();
            if((visited[fron.second.first]==-1) && (assigned.count(fron.second.second)==0))
            {
                visited[fron.second.first]=fron.second.second;
                assigned.insert(fron.second.second);
            }
            if(assigned.size()==wor)
                break;
        }
        return visited;
    }
};
