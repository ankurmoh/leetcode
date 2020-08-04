class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(),people.rend());
        int i=0,sz=people.size(),con=0,cur,j=sz-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                con++;
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit)
            {
                con++;
                i++;
            }
        }
        return con;
    }
};
