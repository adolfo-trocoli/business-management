#include "Employee.h"
#include <string>
using namespace std;

Employee::Employee(int id, string name, int salary, int departmentId) {
    this->id = id;
    this->name = name;
    this->salary = salary;
    this->departmentId = departmentId; 
}
int Employee::getId() const {return id;}
std::string Employee::getName() const {return name;}
void Employee::setName(string name) {this->name = name;}
int Employee::getSalary() const {return salary;}
void Employee::setSalary(int salary) {this->salary = salary;}
int Employee::getDptId() const {return departmentId;}
std::string Employee::toString() {return to_string(id) + " \"" + name + "\" " + to_string(salary) + " " + to_string(departmentId);}
void Employee::setDptId(int departmentId) {this->departmentId = departmentId;}