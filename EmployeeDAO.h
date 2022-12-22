#ifndef EmployeeDAO_h
#define EmployeeDAO_h
#include "Employee.h"
#include "DAO.h"
#include <regex>
#include <optional>
using namespace std;

class EmployeeDAO:
	public DAO<Employee> {
	protected:
		optional<Employee*> readObject(string line) {
			optional<Employee*> employee;
			regex r("(\\d+)\\s\"([\\w\\s.-_?]+)\"\\s(\\d+)\\s(\\d+)");
			smatch m;
			if(regex_search(line, m, r))
				employee = new Employee(stoi(m[1]), m[2], stoi(m[3]), stoi(m[4]));
			return employee;
		}
	public:
		EmployeeDAO(string fileURL) : DAO::DAO(fileURL) {}
};

#endif