#include <iostream>
#include <vector>
#include <string>
#include <fstream> // Add this for file handling
#include <sstream> // Add this for string stream
#include "posts.h"
#include "user.h"

int main() {
    std::string action;
    std::string add;
    std::string create;
    std::string friName;
    std::string userName;
    std::string displayName;
    std::string state;
    std::string userFilePath; // Add this for user file path
    std::string postFilePath; // Add this for post file path

    // Example usage
    PostsManager manager;

    // Add some posts
    manager.addPost(Post("p1924", "petpal4ever", "public"));
    manager.addPost(Post("p9367", "goldenlover1", "friend"));

    // Main Interface for terminal
    while (true) {
        std::cout << "=========================================================" << std::endl;
        std::cout << "Welcome to Assignment 2 Code for Review!" << std::endl;
        std::cout << "Functions:" << std::endl;
        std::cout << "1.) Load input Data" << std::endl;
        std::cout << "2.) Check visibility" << std::endl;
        std::cout << "3.) Search by Location" << std::endl;
        std::cout << "4.) Retrieve Posts" << std::endl;
        std::cout << "5.) Exit" << std::endl;
        std::cout << "=========================================================" << std::endl;

        std::cout << std::endl;
        std::cout << "Enter your Choice: ";

        std::cin >> action;
        std::cout << action << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;

        if (action == "1") {
            std::cout << "Enter user file path: ";
            std::cin >> userFilePath; // Get user file path from user
            std::cout << "Enter post file path: ";
            std::cin >> postFilePath; // Get post file path from user

            // Read user info from file and add users
            std::ifstream userFile(userFilePath);
            if (userFile.is_open()) {
                std::string line;
                while (std::getline(userFile, line)) {
                    std::istringstream iss(line);
                    std::string username, displayName, state, friendsList;
                    if (std::getline(iss, username, ';') && std::getline(iss, displayName, ';') &&
                        std::getline(iss, state, ';') && std::getline(iss, friendsList)) {
                        User user(username, displayName, state);
                        std::istringstream ss(friendsList.substr(1, friendsList.size() - 2));
                        std::string friendUsername;
                        while (std::getline(ss, friendUsername, ',')) {
                            user.addFriend(friendUsername);
                        }
                    } else {
                        std::cerr << "Error: Invalid user info format in file." << std::endl;
                    }
                }
                userFile.close();
            } else {
                std::cerr << "Error: Unable to open user file." << std::endl;
            }

            // Read post info from file and add posts
            std::ifstream postFile(postFilePath);
            if (postFile.is_open()) {
                std::string line;
                while (std::getline(postFile, line)) {
                    std::istringstream iss(line);
                    std::string postId, userId, visibility;
                    if (std::getline(iss, postId, ';') && std::getline(iss, userId, ';') &&
                        std::getline(iss, visibility)) {
                        manager.addPost(Post(postId, userId, visibility));
                    } else {
                        std::cerr << "Error: Invalid post info format in file." << std::endl;
                    }
                }
                postFile.close();
            } else {
                std::cerr << "Error: Unable to open post file." << std::endl;
            }

            std::cout << "Data loaded successfully." << std::endl;

        } else if (action == "2") {
            // Your existing code for checking visibility
            // Retrieve posts for a user
            std::vector<Post> userPosts = manager.getPostsForUser("petpal4ever");
            std::cout << "Posts accessible: ";
            // if None print none else print posts
            if (userPosts.size() <= 0) {
                std::cout << "None" << std::endl;
            } else {
                for (const Post& post : userPosts) {
                    std::cout << "Post ID: " << post.getPostId() << ", Visibility: " << post.getVisibility() << std::endl;
                }
            }
        // get location
        } else if (action == "3") {
            std::cout << user.getLocation() << std::endl;
        // get post id's
        } else if (action == "4") {
            std::cout <<< user.getPostId() << std::endl;
        } else if (action == "5") {
            break; // Exit the program
        } else {
            std::cout << "Invalid choice please try again.." << std::endl;
        }
    }

    return 0;
}
