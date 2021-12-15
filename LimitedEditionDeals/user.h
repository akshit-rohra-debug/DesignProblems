//
// Created by Akshit on 11-12-2021.
//

#ifndef UNTITLED_USER_H
#define UNTITLED_USER_H

#include <string>

class User {
private:
    int id_;
    std::string name_;
    std::string email_;
    std::string contact_;
    std::string address_;
    std::string hashed_password_;
public:
    User() = delete;
    // Basic user, just for the sake of demo
    User(int id, std::string name);

    int get_user_id();
};


#endif //UNTITLED_USER_H
