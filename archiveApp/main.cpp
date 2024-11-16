#include <iostream>
#include <pqxx/pqxx> 
#include "utils.h"

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        pqxx::connection C("dbname=archive user=postgres password=password \
                            hostaddr=127.0.0.1 port=5432");
        if (C.is_open()) {
            std::cout << "Opened database successfully: " << C.dbname() << std::endl;
        }
        else {
            std::cout << "Can't open database" << std::endl;
            return 1;
        }
        int empl_id = 0;
        if (!login(C, empl_id)) // +7(812)783-32-33     +7(812)645-91-72     +7(812)783-83-16   -   номера абонентов
            return 0;
        // doing something...
        get_report_2(C);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}