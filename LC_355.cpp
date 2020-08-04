class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, set<int>>follower;
    unordered_map<int, queue<pair<int,int>> >tweet;
    int time=0;

    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet[userId].push(make_pair(time++,tweetId));
        if(tweet[userId].size()>10)
            tweet[userId].pop();
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int i;
        pair<int,int>fron;
        vector<int>res;
        // priority_queue<pair<int,int>>pq;
        // queue<pair<int,int>>q = tweet[userId];
        // while(!q.empty())
        // {
        //     fron=q.front();
        //     pq.push(fron);
        //     q.pop();
        // }
        // for(auto it=follower[userId].begin();it!=follower[userId].end();it++)
        // {
        // q = tweet[*it];
        // while(!q.empty())
        // {
        //     fron=q.front();
        //     q.pop();
        //     pq.push(fron);
        // }
        // }
        // while(!pq.empty())
        // {
        //     res.push_back(pq.top().second);
        //     pq.pop();
        //     if(res.size()==10)
        //         break;
        // }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        queue<pair<int,int>>q = tweet[userId];
        while(!q.empty())
        {
            fron=q.front();
            q.pop();
            if(pq.size()<10)
                pq.push(fron);
            else if(pq.size()>=10)
            {
                if(fron.first>pq.top().first)
                {
                    pq.pop();
                    pq.push(fron);
                }
            }
        }
        for(auto it=follower[userId].begin();it!=follower[userId].end();it++)
        {
        q = tweet[*it];
        while(!q.empty())
        {
            fron=q.front();
            q.pop();
            if(pq.size()<10)
                pq.push(fron);
            else if(pq.size()>=10)
            {
                if(fron.first>pq.top().first)
                {
                    pq.pop();
                    pq.push(fron);
                }
            }
        }
        }
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
             follower[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
