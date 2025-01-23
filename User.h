#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;
    std::string type;

public:
    User(const std::string& username, const std::string& password, const std::string& type = "");
    virtual ~User() = default;
    std::string getUsername() const;
    std::string getPassword() const; // Добавлен геттер для пароля
    bool checkPassword(const std::string& password) const;
    virtual void displayInfo() const = 0; // Чисто виртуальная функция
    void setType(const std::string& type);
    std::string getType() const;
};

#endif // USER_H