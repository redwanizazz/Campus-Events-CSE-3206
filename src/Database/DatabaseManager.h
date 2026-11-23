#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <string>

class DatabaseManager {
private:
    static DatabaseManager* instance;
    DatabaseManager() {} // Private constructor
public:
    static DatabaseManager* getInstance() {
        if (!instance) instance = new DatabaseManager();
        return instance;
    }
    void executeQuery(const std::string& query);
};

#endif