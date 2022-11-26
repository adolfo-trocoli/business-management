#include "Controller.h"
using namespace std;

Controller* Controller::controller = nullptr;
Controller::Controller(string employeeFile, string departmentFile) {
	EmployeeDAO e(employeeFile);
	DepartmentDAO d(departmentFile);
	empDAO = &e;
	dptDAO = &d;
};
static Controller *Controller::getInstance(const string s) {
	if(controller == nullptr)
		controller = new Controller(s);
	return controller;
}
Employee* Controller::findEmployee(int id) {
	optional<Employee> e = empDAO.find(id);
	if (e.has_value())
		return e.value()
}
Employee** Controller::findEmployees();        
void Controller::createEmployee(std::string name, int departmentId);
void Controller::removeEmployee(Employee employee);
void Controller::updateEmployee(Employee employee);

Department* Controller::findDepartment(int id);
Department** Controller::findDepartments();
void Controller::createDepartment(std::string name, int sells, int managerId);
void Controller::removeDepartment(Department dpt);
void Controller::updateDepartment(Department dpt);