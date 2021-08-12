#include "databasehandler.h"
#include <iostream>

std::vector<std::vector<std::string*>> DatabaseHandler::result_set {};

DatabaseHandler::DatabaseHandler()
{

}

bool DatabaseHandler::open_database(const std::string &db_name)
{
    int result = sqlite3_open(db_name.c_str(), &m_db);
    if (SQLITE_OK != result)
        return false;

    return true;
}

bool DatabaseHandler::execute_query(std::string &query,
                                    std::string &error_message)
{
    char** err_msg;
    result_set.clear();
    int result = sqlite3_exec(m_db, query.c_str(), callback, 0, err_msg);
    if (SQLITE_OK != result)
        return false;

    return true;
}

bool DatabaseHandler::execute(std::string &query)
{
    int result = sqlite3_exec(m_db, query.c_str(), NULL, 0, NULL);
    if (SQLITE_OK != result)
        return false;

    return true;

}

int DatabaseHandler::callback(void *data, int argc,
                              char **argv, char **azColumn)
{
    std::vector<std::string*> row_vector;
    for (int row = 0; row < argc; row++)
    {
        if (argv[row])
            row_vector.push_back(new std::string(argv[row]));
        else
            row_vector.push_back(nullptr);
    }

    result_set.push_back(row_vector);
    return 0;
}

std::vector<std::vector<std::string *>> DatabaseHandler::get_result()
{
    return result_set;

}










