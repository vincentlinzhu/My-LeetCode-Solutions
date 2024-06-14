// My Version:
class Twitter {
private:
    unordered_map<int, set<int>> f;
    unordered_map<int, vector<pair<int, int>>> posts;
    int time = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (posts.count(userId)) {
            posts[userId].push_back(pair<int, int>(time, tweetId));
        } else {
            vector<pair<int, int>> v;
            v.push_back(pair<int, int>(time, tweetId));
            posts[userId] = v;
        }
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        f[userId].insert(userId);
        // merge all the posts of all the people that userId follows
        for (auto x : f[userId]) {
            for (auto y : posts[x]) {
                pq.push(y);
            }
        }
        while (res.size() < 10 && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (f.count(followerId)) {
            f[followerId].insert(followeeId);
        } else {
            set<int> s;
            s.insert(followeeId);
            f[followerId] = s;
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (f[followerId].count(followeeId)) {
            f[followerId].erase(followeeId);
        }
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

 // His Version:
 class Twitter {
private:
    unordered_map<int, set<int>> f;
    unordered_map<int, vector<pair<int, int>>> posts;
    int time = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (posts.count(userId)) {
            posts[userId].push_back(pair<int, int>(time, tweetId));
        } else {
            vector<pair<int, int>> v;
            v.push_back(pair<int, int>(time, tweetId));
            posts[userId] = v;
        }
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        vector<vector<int>> v;
        priority_queue<vector<int>> pq;
        int index;
        int time;
        int tweetId;
        int followeeId;
        f[userId].insert(userId);
        // merge all the posts of all the people that userId follows
        for (auto x : f[userId]) {
            if (posts.count(x) != 0) {
                index = posts[x].size() - 1;
                time = posts[x][index].first;
                tweetId = posts[x][index].second;
                pq.push({time, tweetId, x, index - 1});
            }
        }
        while (res.size() < 10 && !pq.empty()) {
            res.push_back(pq.top()[1]);
            followeeId = pq.top()[2];
            index = pq.top()[3];
            pq.pop();
            if (index >= 0) {
                time = posts[followeeId][index].first;
                tweetId = posts[followeeId][index].second;
                pq.push({time, tweetId, followeeId, index - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (f.count(followerId)) {
            f[followerId].insert(followeeId);
        } else {
            set<int> s;
            s.insert(followeeId);
            f[followerId] = s;
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (f[followerId].count(followeeId)) {
            f[followerId].erase(followeeId);
        }
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