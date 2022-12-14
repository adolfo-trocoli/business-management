#include "Controller.h"
#include <iostream>
using namespace std;

// --- Singleton constructor --- 
Controller* Controller::controller = nullptr;
Controller::Controller(string employeeFile, string departmentFile, Helper& h)
	: empDAO(new EmployeeDAO(employeeFile)),
	  dptDAO(new DepartmentDAO(departmentFile)),
	  helper(h) {};

Controller *Controller::getInstance(string employeeFile, string departmentFile, Helper& helper) {
	if(controller == nullptr)
		controller = new Controller(employeeFile, departmentFile, helper);
	return controller;
}

// --- Bussiness public member functions ---
void Controller::displayHelp() {
	cout << helper.help();
}

void Controller::displayHelp(string command) {
	cout << helper.help(command);
}

void Controller::lsEmployees() {
	using std::cout;
	vector<Employee*> list = empDAO->findAll();
	cout << "Employee list:" << endl;
	for (Employee* e : list)
		cout << e->toString() << endl;
	cout << endl;
}

void Controller::lsDepartments() {
	vector<Department*> list = dptDAO->findAll();
	cout << "Department list: " << endl;
	for (Department* d : list)
		cout << d->toString() << endl;
	cout << endl;
}

// --- DB-Related public member functions ---
void Controller::showEmployee(int id) {
	optional<Employee*> e = empDAO->find(id); 
	if(e.has_value()) 
		cout << e.value()->toString() << endl;
	else 
		cout << "No employee found for id: " << to_string(id) << endl;
}
optional<Employee*> Controller::findEmployee(int id) {
	return empDAO->find(id);
}
vector<Employee*> Controller::findEmployees() {
	return empDAO->findAll();
}        
void Controller::createEmployee(std::string name, int departmentId) {
	if(!checkDptId(departmentId)) throw 21;
	int id = selectEmployeeId();
	Employee employee(id, name, departmentId);
	empDAO->create(employee);
}
void Controller::removeEmployee(int id) {
	empDAO->deletion(id);
}
void Controller::updateEmployee(int id, string name, int departmentId) {
	if(!checkDptId(departmentId)) throw 21;
	Employee employee(id, name, departmentId);
	empDAO->update(employee);
}
optional<Department*> Controller::findDepartment(int id) {
	return dptDAO->find(id);
}
void Controller::showDepartment(int id) {
	optional<Department*> d = dptDAO->find(id); 
	if(d.has_value())
		cout << d.value()->toString() << endl;
	else 
		cout << "No department found for id: " << to_string(id) << endl;
}
vector<Department*> Controller::findDepartments() {
	return dptDAO->findAll();
}        	
void Controller::createDepartment(std::string name, int sells, int managerId) {
	if(!checkManagerId(managerId)) throw 22;
	int id = selectDepartmentId();
	Department department(id, name, sells, managerId);
	dptDAO->create(department);
}
void Controller::removeDepartment(int id) {
	dptDAO->deletion(id);
}
void Controller::updateDepartment(int id, string name, int sells, int managerId) {
	if(!checkManagerId(managerId)) throw 22;
	Department department(id, name, sells, managerId);
	dptDAO->update(department);
}

// --- Private member functions ---
// No sé si hacer uno para empleados y departamentos o uno para cada uno
int Controller::selectEmployeeId() {
	return empDAO->maxId() + 1;
}

int Controller::selectDepartmentId() {
	return dptDAO->maxId() + 1;
}

bool Controller::checkManagerId(int id) {
	return empDAO->idExists(id);
}

bool Controller::checkDptId(int id) {
	return dptDAO->idExists(id);
}