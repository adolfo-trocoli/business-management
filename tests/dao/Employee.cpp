#include "Employee.h"
#include <string>
using namespace std;

Employee::Employee(int id, string name, int departmentId) {
    this->id = id;
    this->name = name;
    this->departmentId = departmentId; 
}
int Employee::getId() const {return id;}
std::string Employee::getName() const {return name;}
int Employee::getDptId() const {return departmentId;}
std::string Employee::toString() {return to_string(id) + " \"" + name + "\" " + to_string(departmentId);}
void Employee::setDptId(int departmentId) {this->departmentId = departmentId;}