#ifndef USERFACTORY_H
#define USERFACTORY_H
#include <string>

class User { 
public: 
    virtual std::string getRole() = 0; 
    virtual ~User() = default;
};

class Student : public User { 
public: 
    std::string getRole() override { return "Student"; } 
};

class Organizer : public User { 
public: 
    std::string getRole() override { return "Organizer"; } 
};

class UserFactory {
public:
    static User* createUser(const std::string& type) {
        if (type == "Student") return new Student();
        if (type == "Organizer") return new Organizer();
        return nullptr;
    }
};

#endif