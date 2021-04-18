// Runtime: 84 ms, faster than 20.96% of C++ online submissions for Design Twitter.
// Memory Usage: 23.5 MB, less than 33.33% of C++ online submissions for Design Twitter.

#include <map>
#include <unordered_map>
#include <unordered_set>

using pii = std::pair<int,int>;

struct pair_hash
{
    inline std::size_t operator()(const std::pair<int,int>& v) const
    {
        return v.first*31+v.second;
    }
};

class Twitter
{
public:
    Twitter(){}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        pii userAndTweetIds = std::make_pair(userId, tweetId);
        newsFeed[userId].insert(std::make_pair(++commId, userAndTweetIds));
        for (pii followerAndFollowee : followHistory)
        {
            if (followerAndFollowee.second == userId)
            {
                newsFeed[followerAndFollowee.first].insert(std::make_pair(commId, userAndTweetIds));
            }
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    std::vector<int> getNewsFeed(int userId)
    {
        std::vector<int> tweetIds;
        for (auto it = newsFeed[userId].rbegin(); it != newsFeed[userId].rend(); ++it)
        {
            tweetIds.push_back(it->second.second);
            if (tweetIds.size() == 10)
            {
                return tweetIds;
            }
        }
        return tweetIds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            pii followerAndFollowee = std::make_pair(followerId, followeeId);
            followHistory.insert(followerAndFollowee);
            for (auto kv : newsFeed[followeeId])
            {
                pii followerAndOtherFollowee = std::make_pair(followerId, kv.second.first);
                if (followHistory.find(followerAndOtherFollowee) != followHistory.end())
                {
                    newsFeed[followerId].insert(kv);
                }
            }
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            pii followerAndFollowee = std::make_pair(followerId, followeeId);
            followHistory.erase(followerAndFollowee);
            for (auto kv : newsFeed[followerId])
            {
                if (kv.second.first == followeeId)
                {
                    newsFeed[followerId].erase(kv.first);
                }
            }
        }
    }
    
private:
    std::unordered_map<int, std::map<int,pii>> newsFeed;
    std::unordered_set<pii, pair_hash> followHistory;
    int commId = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
