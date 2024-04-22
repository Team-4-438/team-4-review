#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

// Define User class
class User {

private:
    std::string username;
    std::string displayName;
    std::string state;
    std::vector<std::string> friends;

public:
    // Constructor
    User(std::string username, std::string displayName, std::string state);

    // Getter for username
    std::string getUsername() const;

    // Getter for display name
    std::string getDisplayName() const;

    // Getter for state
    std::string getState() const;

    // Function to add a friend
    void addFriend(std::string friendUsername);

    // Function to print user details
    void printDetails() const;
};

#endif // USER_H
