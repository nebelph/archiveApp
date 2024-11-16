#include "utils.h"

bool login(pqxx::connection& C, int& id) {
	std::string phone_number = "";
	std::cout << "Enter your phone number: ";
	std::cin >> phone_number;
	try {
		pqxx::work W(C);
		std::string query = "SELECT COUNT(*) FROM employee WHERE employee_phone = '" + phone_number + "';";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			if (R[0][0].as<int>() != 0) {
				query = "SELECT employee_id FROM employee WHERE employee_phone = '" + phone_number + "';";
				pqxx::result R = W.exec(query);
				id = R[0][0].as<int>();
				std::cout << "You are logged in!\n";
				return true;
			}
		}
		std::cout << "Wrong phone number!\n";
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 0;
	}
	return false;
}


void fill_doc(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Technical manual for the operation of equipment X', 'Equipment operation', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Maintenance instructions for equipment Y', 'Technical maintenance', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Regulations for the preventive maintenance of equipment Z', 'Technical maintenance', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Production safety manual', 'Safety', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Calibration methodology for measuring instruments', 'Calibration', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Report on the testing of equipment A', 'Testing', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Technical requirements for system B', 'Technical requirements', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Modernization plan for equipment C', 'Modernization', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('User guide for software D', 'Software', CURRENT_DATE);";
		W.exec(query);
		query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('Safety recommendations for equipment Y', 'Safety', CURRENT_DATE);";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void fill_rack(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "INSERT INTO rack DEFAULT VALUES;";
		W.exec(query);
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void fill_shelf(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "INSERT INTO shelf (rack_id) VALUES (1);";
		W.exec(query);
		query = "INSERT INTO shelf (rack_id) VALUES (1);";
		W.exec(query);
		query = "INSERT INTO shelf (rack_id) VALUES (2);";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void fill_instance(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "INSERT INTO instance (doc_id) VALUES (3);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (7);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (1);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (2);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (1);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (5);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (9);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (3);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (6);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (7);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (1);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (3);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (5);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (2);";
		W.exec(query);
		query = "INSERT INTO instance (doc_id) VALUES (1);";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void fill_cell(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "INSERT INTO cell (shelf_id, doc_id) VALUES (1, 3);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (1, 1);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (1, 9);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (1, 10);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (2, 2);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (2, 4);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (2, 6);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (3, NULL);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (3, 8);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		query = "INSERT INTO cell (shelf_id, doc_id) VALUES (3, 7);";
		W.exec(query);
		query = "UPDATE cell SET instance_number = (SELECT COUNT(*) FROM instance WHERE instance.doc_id = cell.doc_id);";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void fill_department(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "INSERT INTO department (department_phone) VALUES ('+7(812)923-97-24');";
		W.exec(query);
		query = "INSERT INTO department (department_phone) VALUES ('+7(812)807-65-41');";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void fill_employee(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "INSERT INTO employee (department_id, employee_name, employee_phone) VALUES ('1', 'Ivanov I.I.', '+7(812)783-32-33');";
		W.exec(query);
		query = "INSERT INTO employee (department_id, employee_name, employee_phone) VALUES ('1', 'Petrov P.P.', '+7(812)645-91-72');";
		W.exec(query);
		query = "INSERT INTO employee (department_id, employee_name, employee_phone) VALUES ('2', 'Sidorov S.S.', '+7(812)783-83-16');";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void select_all(std::string tb_name, pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "SELECT * FROM " + tb_name + ";";
		pqxx::result R = W.exec(query);
		for (auto row : R) {
			for (auto field : row) {
				std::cout << field.c_str() << '\t';
			}
			std::cout << '\n';
		}
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}


void truncate_cascade(std::string tb_name, pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "TRUNCATE " + tb_name + " CASCADE;";
		pqxx::result R = W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int count_docs_by_topic(std::string topic, pqxx::connection& C) {
	int retval = 0;
	try {
		pqxx::work W(C);
		std::string query = "SELECT COUNT(*) FROM doc WHERE doc_topic = '" + topic + "';";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			return R[0][0].as<int>();
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 0;
	}
	return retval;
}

std::string find_topic_by_doc_name(std::string name, pqxx::connection& C) {
	std::string retval = "";
	try {
		pqxx::work W(C);
		std::string query = "SELECT doc_topic FROM doc WHERE doc_name = '" + name + "';";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			return R[0][0].as<std::string>();
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return "";
	}
	return retval;
}

std::string find_doc_name_with_largest_inst_num(pqxx::connection& C) {
	std::string retval = "";
	try {
		pqxx::work W(C);
		std::string query = "SELECT doc_name FROM doc\
				WHERE(doc_id = (\
				SELECT doc_id FROM cell\
				WHERE instance_number = (\
				SELECT MAX(instance_number)\
				FROM cell\
				)));";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			return R[0][0].as<std::string>();
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return "";
	}
	return retval;
}

std::string find_doc_name_most_requested(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "SELECT doc_name FROM doc\
			WHERE doc_id =\
			(SELECT doc_id FROM\
			(SELECT doc_id, COUNT(doc_id)\
			FROM request\
			GROUP BY doc_id\
			ORDER BY doc_id)\
			WHERE count =\
			(SELECT MAX(count) FROM\
			(SELECT doc_id, COUNT(doc_id)\
			FROM request\
			GROUP BY doc_id\
			ORDER BY doc_id)\
			)\
			LIMIT 1);";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			return R[0][0].as<std::string>();
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return "";
	}
	return "";
}

std::string find_department_most_requested(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "SELECT department_id FROM employee\
			WHERE employee_id = (\
			SELECT employee_id FROM(\
			SELECT employee_id, COUNT(employee_id)\
			FROM request\
			GROUP BY employee_id\
			ORDER BY employee_id)\
			WHERE count = (\
			SELECT MAX(count) FROM(\
			SELECT employee_id, COUNT(employee_id)\
			FROM request\
			GROUP BY employee_id\
			ORDER BY employee_id)));";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			return R[0][0].as<std::string>();
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return "";
	}
	return "";
}

std::string find_empl_name_by_last_request(std::string doc_name, pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "SELECT employee_name FROM employee\
			WHERE employee_id = (\
			SELECT employee_id FROM request\
			WHERE doc_id = (\
			SELECT doc_id FROM doc\
			WHERE doc_name = '" + doc_name + "'\
			)\
			ORDER BY request_id DESC\
			LIMIT 1);";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			return R[0][0].as<std::string>();
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return "";
	}
	return "";
}
void fill_doc(std::string doc_name, std::string doc_topic, pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "INSERT INTO doc (doc_name, doc_topic, doc_date) VALUES ('" + doc_name + "', '" + doc_topic + "', CURRENT_DATE);";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void update_department_phone(int department_id, std::string new_phone, pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "UPDATE department SET department_phone = '" + new_phone + "' WHERE department_id = '" + std::to_string(department_id) + "';";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void delete_doc_inst(int doc_id, pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "UPDATE cell SET instance_number = instance_number - 1 WHERE doc_id = '" + std::to_string(doc_id) + "' AND instance_number > 0;";
		W.exec(query);
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}


std::string doRequest(pqxx::connection& C, int& empl_id) {
	std::string retval = "";
	int doc_id = 0;
	std::cout << "Enter document ID (Request): ";
	std::cin >> doc_id;
	try {
		pqxx::work W(C);
		std::string query = "SELECT doc_name FROM doc WHERE doc_id = '" + std::to_string(doc_id) + "';";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			retval = R[0][0].as<std::string>();
			query = "INSERT INTO request (doc_id, employee_id, request_date) VALUES ('" + std::to_string(doc_id) + "', '" + std::to_string(empl_id) + "', CURRENT_DATE);";
			W.exec(query);
			W.commit();
			return retval;
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return "";
	}
	return retval;
}

void get_report_1(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "SELECT * FROM employee;";
		pqxx::result R = W.exec(query);
		for (auto row : R) {
			for (auto field : row) {
				std::cout << field.c_str() << '\t';
			}
			std::cout << '\n';
		}
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void get_report_2(pqxx::connection& C) {
	try {
		pqxx::work W(C);
		std::string query = "SELECT COUNT(*) cell_id FROM cell;";
		pqxx::result R = W.exec(query);
		if (!R.empty()) {
			std::cout << "Число единиц хранения - " << R[0][0].as<int>() << std::endl;
		}
		query = "\
			SELECT cell_id, instance_number, doc_name FROM\
			(\
			SELECT cell_id, cell.doc_id, instance_number, doc_name\
			FROM cell JOIN doc ON cell.doc_id = doc.doc_id\
			)\
			WHERE doc_id IN\
			(\
			SELECT doc_id FROM doc WHERE doc_date >= doc_date - 31\
			)\
			ORDER BY cell_id;";
		R = W.exec(query);
		std::cout << "Ячейка\tКол-во\tНазвание документа\n";
		for (auto row : R) {
			for (auto field : row) {
				std::cout << field.c_str() << '\t';
			}
			std::cout << '\n';
		}
		W.commit();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}