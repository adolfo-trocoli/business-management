#include "Controller.h"
using namespace std;

Controller* Controller::controller = nullptr;
Controller::Controller(string employeeFile, string departmentFile, Helper& helper) {
	EmployeeDAO e(employeeFile);
	DepartmentDAO d(departmentFile);
	this->helper = helper;
	empDAO = &e;
	dptDAO = &d;
};
static Controller *Controller::getInstance(string employeeFile, string departmentFile) {
	if(controller == nullptr)
		controller = new Controller(employeeFile, departmentFile);
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