#ifndef POSTS_H
#define POSTS_H

#include <string>
#include <vector>

class Post {
private:
    std::string postId;
    std::string userId;
    std::string visibility;

public:
    Post(std::string postId, std::string userId, std::string visibility);

    std::string getPostId() const;
    std::string getUserId() const;
    std::string getVisibility() const;
};

class PostsManager {
private:
    std::vector<Post> posts;

public:
    void addPost(const Post& post);
    std::vector<Post> getPostsForUser(const std::string& userId) const;
    std::vector<std::string> searchUsersByLocation(const std::string& location, const std::vector<std::string>& users) const;
};

#endif // POSTS_H
