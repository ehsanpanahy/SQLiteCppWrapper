#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include "sqlite3/sqlite3.h"
#include <string>
#include <vector>

class DatabaseHandler
{
public:
    DatabaseHandler();
    bool open_database(const std::string &db_name);

    bool execute_query(std::string &query, std::string &error_message);
    bool execute(std::string &query);

     static int callback(void* data, int argc, char** argv, char** azColumn);

     std::vector<std::vector<std::string*>>  get_result();

     static std::vector<std::vector< std::string*>> result_set;

private:
    sqlite3 *m_db;



};

#endif // DATABASEHANDLER_H
