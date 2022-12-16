#ifndef DepartmentDAO_h
#define DepartmentDAO_h
#include "Department.h"
#include "DAO.h"
#include <regex>
#include <optional>
using namespace std;

// Esta clase sigue siendo abstracta hasta que no implemente lo métodos virtuales puros de la superclase.
// Los ids están declarados como estáticos pero si no tiene en cuenta en el constructor el último que ya hay escrito en el archivo, se van a repetir y se va a rayar.
class DepartmentDAO:
	public DAO<Department> {
	protected:
		optional<Department*> readObject(string line) {
			optional<Department*> department;
			regex r("(\\d+)\\s\"([\\w\\s.-_?]+)\"\\s(\\d+)\\s(\\d+)");
			smatch m;
			if(regex_search(line, m, r)) {
				department = new Department(stoi(m[1]), m[2], stoi(m[3]), stoi(m[4]));
			}
			return department;
		}
	public:
		DepartmentDAO(string fileURL) : DAO::DAO(fileURL) {}
		optional<Department*> departmentByManagerId(int id) {
			optional<Department*> dpt;
			ifstream file(fileURL);
			regex r("\\d+\\s\"[\\w\\s.-_?]+\"\\s\\d+\\s" + to_string(id) + "[\\n\\s]?");
			smatch m;
			string line;
			while(getline(file, line)) {
				if(regex_search(line, m, r)) 
					dpt = readObject(line);
			}
			return dpt;
		}
};

#endif