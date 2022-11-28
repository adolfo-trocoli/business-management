#include "Controller.h"
using namespace std;

// --- Singleton constructor --- 
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

// --- Bussiness public member functions ---
void displayHelp() {
	helper.help();
}

void displayHelp(string command) {
	helper.help(command);
}

// Yet to be added most features
void lsEmployees() {
	vector<Employee*> list = empDAO.findAll();
	for (Employee* e : list)
		e->print();
}

void lsDepartments() {
	vector<Department*> list = dptDAO.findAll();
	for (Department* d : list)
		d->print();
}

// --- DB-Related public member functions ---
optional<Employee*> Controller::findEmployee(int id) {
	return empDAO.find(id);
}
vector<Employee*> Controller::findEmployees() {
	return empDAO.findAll();
}        
bool Controller::createEmployee(std::string name, int departmentId) {
	int id = selectEmployeeId();
	if(!checkDptID(departmentId)) return false;
	Employee employee(id, name, departmentId);
	empDAO.create(employee);
	return true;
}
void Controller::removeEmployee(int id) {
	empDAO.deletion(id);
}
void Controller::updateEmployee(int id, string name, int departmentId) {
	Employee employee(id, name, departmentId);
	empDAO.update(employee);
}
optional<Department*> Controller::findDepartment(int id) {
	return dptDAO.find(id);
}
vector<Department*> Controller::findDepartments() {
	return dptDAO.findAll();
}        	
bool Controller::createDepartment(std::string name, int sells, int managerId) {
	int id = selectDepartmentId();
	if(!checkManagerId(managerId)) return false;
	Department department(id, name, sells, managerId);
	dptDAO.create(department);
	return true;
}
void Controller::removeDepartment(int id) {
	dptDAO.deletion(id);
}
void Controller::updateDepartment(int id, string name, int sells, int managerId) {
	Department department(id, name, sells, managerId);
	dptDAO.update(department);
}

// --- Private member functions ---
// No sé si hacer uno para empleados y departamentos o uno para cada uno
int Controller::selectEmployeeId() {
	return empDAO.maxId();
}

int Controller::selectDepartmentId() {
	return dptDAO.maxId();
}

bool checkManagerId(int id) {
	return empDAO.idExists(id);
}

checkDptId(int id) {
	return dptDAO.idExists(id);
}