class Twitter {
    static class Posts {
        public int priority;
        public int tweetId;

        public Posts(int priority, int tweetId) {
            this.priority = priority;
            this.tweetId = tweetId;
        }
    }
    private Map<Integer, List<Integer>> followMap;
    private Map<Integer, ArrayDeque<Posts>> postMap;
    private int allTweets;
    
    public Twitter() {
        followMap = new HashMap<>();
        postMap = new HashMap<>();
        allTweets = 0;
    }
    
    public void postTweet(int userId, int tweetId) {
        ArrayDeque<Posts> st = postMap.getOrDefault(userId, new ArrayDeque<>());
        st.offerFirst(new Posts(allTweets, tweetId));
        postMap.put(userId, st);
        allTweets++;
    }
    
    public List<Integer> getNewsFeed(int userId) {
        int tweets = 0;
        List<Integer> newsFeed = new ArrayList<>();
        List<Integer> followers = followMap.getOrDefault(userId, new ArrayList<>());
        List<ArrayDeque<Posts>> posts = new ArrayList<>();

        ArrayDeque<Posts> myPosts = postMap.get(userId);
        if(myPosts != null) {
            posts.add(new ArrayDeque<>(myPosts));
        }

        for(int i=0; i<followers.size(); i++) {
            ArrayDeque<Posts> anotherPosts = postMap.get(followers.get(i));
            if(anotherPosts != null) {
                posts.add(new ArrayDeque<>(anotherPosts));
            }
        }

        while(tweets < 10) {
            int priority = -1;
            int idx = -1;
            int emptyStack = 0;
            System.out.println(posts.size() + " " + tweets);
            for(int i=0; i<posts.size(); i++) {
                ArrayDeque<Posts> showPosts = posts.get(i);
                if(showPosts.isEmpty()) {
                    emptyStack++;
                    continue;
                }
                Posts post = showPosts.getFirst();
                System.out.println(post.priority + " " + priority);
                if(priority < post.priority) {
                    idx = i;
                    priority = post.priority;
                }
            }

            if(emptyStack == posts.size())
                break;
            System.out.println(posts.get(idx).getFirst().tweetId);
            newsFeed.add(posts.get(idx).getFirst().tweetId);
            posts.get(idx).pollFirst();
            tweets++;
        }

        return newsFeed;
    }

    public void follow(int followerId, int followeeId) {
        List<Integer> followers = followMap.get(followerId);
        if(followers == null) {
            followers = new ArrayList<>();
        }
        if(!followers.contains(followeeId))
            followers.add(followeeId);
        followMap.put(followerId, followers);
    }
    
    public void unfollow(int followerId, int followeeId) {
        List<Integer> followers = followMap.get(followerId);
        if(followers == null)
            return;
        
        followers.removeIf(val -> val == followeeId);
        followMap.put(followerId, followers);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
