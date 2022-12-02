#ifndef EmployeeDAO_h
#define EmployeeDAO_h
#include "Employee.h"
#include "DAO.h"
#include <regex>
#include <optional>
using namespace std;

// Esta clase sigue siendo abstracta hasta que no implemente lo métodos virtuales puros de la superclase.
// Los ids están declarados como estáticos pero si no tiene en cuenta en el constructor el último que ya hay escrito en el archivo, se van a repetir y se va a rayar.
class EmployeeDAO:
	public DAO<Employee> {
	protected:
		optional<Employee*> readObject(string line) {
			optional<Employee*> employee;
			regex r("(\\d+)\\s\"([\\w\\s.-_?]+)\"\\s(\\d+)");
			smatch m;
			if(regex_search(line, m, r))
				employee = new Employee(stoi(m[1]), m[2], stoi(m[3]));
			return employee;
		}
	public:
		EmployeeDAO(string fileURL) : DAO::DAO(fileURL) {}
};

#endif