#include "User.h"
#include <iostream>
#include "utils.h"

User::User(const std::string& username, const std::string& password, const std::string& type)
    : username(username), password(password), type(type) {
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

bool User::checkPassword(const std::string& password) const {
    return this->password == hashPassword(password);
}

void User::setType(const std::string& type) {
    this->type = type;
}

std::string User::getType() const {
    return type;
}