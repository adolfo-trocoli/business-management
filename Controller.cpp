#include "Controller.h"
using namespace std;

// - Singleton constructor ------------------
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

// - Public member functions ----------------
void displayHelp() {
	helper.help();
}

void displayHelp(string command) {
	helper.help(command);
}
optional<Employee*> Controller::findEmployee(int id) {
	return empDAO.find(id);
}
optional<vector<Employee*>> Controller::findEmployees() {
	return empDAO.findAll();
}        
bool Controller::createEmployee(std::string name, int departmentId) {
	int id = selectId();
	if(!checkDptID(departmentId)) return false;
	Employee employee(id, name, departmentId);
	empDAO.create(employee);
	return true;
}
void Controller::removeEmployee(Employee employee) {
	empDAO.deletion(employee);
}
void Controller::updateEmployee(Employee employee) {
	empDAO.update(employee);
}

optional<Department*> Controller::findDepartment(int id) {
	return empDAO.find(id);
}
optional<vector<Department*>> Controller::findDepartments() {
	return empDAO.findAll();
}        
bool Controller::createDepartment(std::string name, int sells, int managerId) {
	int id = selectId();
	if(!checkName(name) || !checkManagerId(managerId)) return false;
	Department department(id, name, sells, managerId);
	empDAO.create(department);
	return true;
}
void Controller::removeDepartment(Department department) {
	empDAO.deletion(department);
}
void Controller::updateDepartment(Department department) {
	empDAO.update(department);
}

// No sé si hacer uno para empleados y departamentos o uno para cada uno
int Controller:selectId();
checkName();
checkManagerId();
checkDptId();