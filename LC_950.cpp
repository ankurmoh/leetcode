class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int i,len=deck.size(),fron;
        sort(deck.begin(),deck.end());
        vector<int>res(len);
        queue<int>q;
        for(i=0;i<len;i++)
            q.push(i);
        for(i=0;i<len;i++)
        {
            fron=q.front();
            q.pop();
            res[fron]=deck[i];
            fron=q.front();
            q.pop();
            q.push(fron);
        }
        return res;
    }
};
