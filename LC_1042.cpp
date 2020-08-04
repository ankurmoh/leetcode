class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>>graph(N+1);
        vector<int>options = {1,2,3,4};
        int i,sz=paths.size(),src,parent,neighbor,col,j,k;
        bool found;
        for(i=0;i<sz;i++)
        {
            graph[paths[i][0]-1].push_back(paths[i][1]-1);
            graph[paths[i][1]-1].push_back(paths[i][0]-1);
        }

        vector<int>res(N,-1);
       for(i=0;i<N;i++)
       {
           for(k=0;k<4;k++)
           {
               col = options[k];
               found=false;
               for(j=0;j<graph[i].size();j++)
               {
                   if((res[graph[i][j]]!=-1) && (res[graph[i][j]]==col))
                       found=true;
               }
               if(!found)
               {
                   res[i]=col;
                   break;
               }
           }
       }
        return res;
    }
};
