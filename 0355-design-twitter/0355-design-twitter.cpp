class Twitter {
public:
    vector<pair<int,int>> v;
    map<int,map<int,int>> mp;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        v.push_back(make_pair(userId,tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> v1;
        int count = 0;

        for(int i=v.size()-1;i>=0 && count < 10;i--){
            if(v[i].first == userId || mp[userId][v[i].first]){
                v1.push_back(v[i].second);
                count++;
            }
        }

        return v1;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId][followeeId] = 0;
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