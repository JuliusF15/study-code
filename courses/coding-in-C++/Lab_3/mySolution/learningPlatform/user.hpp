#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <iostream>

class User {
private:
    std::string user_name;
    std::string user_email;
    int user_id;

public:
    User(): user_name(""), user_email(""), user_id(-1) {};
    User(std::string name, std::string email, int id): user_name(name), user_email(email), user_id(id) {};
    ~User();

    void setUserName(const std::string& name){
        user_name = name;
    }; 
    void setUserEmail(const std::string& email){
        user_email = email;
    };
    void setUserId(int id){
        user_id = id;
    };
    void getUserInfo(std::string& name, std::string& email, int& id){
        name = user_name;
        email = user_email;
        id = user_id;
    };
};

#endif // USER_HPP