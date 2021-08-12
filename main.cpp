#include <iostream>
#include <database/databasehandler.h>
using namespace std;

int main()
{
    DatabaseHandler handler;
    handler.open_database("staffs.db");
    //std::string add = "INSERT INTO department locationid VALUES 'testloc'";
    //handler.execute(add);
    std::string select = "SELECT * FROM department";
    std::string err;
    handler.execute_query(select, err);
    auto p = handler.get_result();

    auto j = p.at(0).at(1)->c_str();
    cout << "" << endl;
    return 0;
}





