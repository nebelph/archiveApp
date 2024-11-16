#pragma once
#include <iostream>
#include <pqxx/pqxx>
#include <string>

bool login(pqxx::connection&, int&);
void fill_doc(pqxx::connection&);
void fill_rack(pqxx::connection&);
void fill_shelf(pqxx::connection&);
void fill_instance(pqxx::connection&);
void fill_cell(pqxx::connection&);
void fill_department(pqxx::connection&);
void fill_employee(pqxx::connection&);
void select_all(std::string, pqxx::connection&);
void truncate_cascade(std::string, pqxx::connection&);
int count_docs_by_topic(std::string, pqxx::connection&);
std::string find_topic_by_doc_name(std::string, pqxx::connection&);
std::string find_doc_name_with_largest_inst_num(pqxx::connection&);
std::string find_doc_name_most_requested(pqxx::connection&);
std::string find_department_most_requested(pqxx::connection&);
std::string find_empl_name_by_last_request(std::string, pqxx::connection&);
void fill_doc(std::string, std::string, pqxx::connection&);
void update_department_phone(int, std::string, pqxx::connection&);
void delete_doc_inst(int, pqxx::connection&);
std::string doRequest(pqxx::connection&, int&);
void get_report_1(pqxx::connection&);
void get_report_2(pqxx::connection&);
