#include "user.h"
#include <iostream>

// Constructor implementation
User::User(std::string username, std::string displayName, std::string state) {
    this->username = username;
    this->displayName = displayName;
    this->state = state;
}

// Getter for username implementation
std::string User::getUsername() const {
    return username;
}

// Getter for display name implementation
std::string User::getDisplayName() const {
    return displayName;
}

// Getter for state implementation
std::string User::getState() const {
    return state;
}

// Function to add a friend implementation
void User::addFriend(std::string friendUsername) {
    friends.push_back(friendUsername);
}

// Function to print user details implementation
void User::printDetails() const {
    std::cout << "Username: " << username << std::endl;
    std::cout << "Display Name: " << displayName << std::endl;
    std::cout << "State: " << state << std::endl;
    std::cout << "Friends: ";
    for (const std::string& friendUsername : friends) {
        std::cout << friendUsername << " ";
    }
    std::cout << std::endl;
}
