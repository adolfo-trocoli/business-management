#include "Controller.h"
#include <iostream>
using namespace std;

// --- Singleton constructor --- 
Controller* Controller::controller = nullptr;
Controller::Controller(string employeeFile, string departmentFile, Helper& h)
	: empDAO(new EmployeeDAO(employeeFile)),
	  dptDAO(new DepartmentDAO(departmentFile)),
	  helper(h) {};

Controller::~Controller() {
	delete empDAO;
	delete dptDAO;
}

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
	for (Employee* e : list) {
		cout << e->toString() << endl;
		delete e;
	}
	cout << endl;
}

void Controller::lsDepartments() {
	vector<Department*> list = dptDAO->findAll();
	cout << "Department list: " << endl;
	for (Department* d : list) {
		cout << d->toString() << endl;
		delete d;
	}
	cout << endl;
}

void Controller::showManagerForDpt (int id) {
	optional<Employee*> emp = managerForDpt(id);
	if(emp.has_value()) {
		showEmployee(emp.value()->getId());
		delete emp.value();
	} else
		throw 24;
}

void Controller::showIsManager(int id) {
	optional<Department*> dpt = departmentForManager(id); 
	if(dpt.has_value()) {
		managerMessage(dpt.value());
		delete dpt.value();
	} else
		noManagerMessage();
}

void Controller::showEmployeesForDpt(int dptId) {
	optional<Department*> dpt = dptDAO->find(dptId);
	if(!dpt.has_value())
		throw 23;
	vector<Employee*> emps = employeesForDpt(dpt.value()->getId());
	if(emps.empty()) 
		cout << "No employees for department \"" + dpt.value()->getName() + "\"." << endl;
	else {
		cout << "Employees working for department \"" + dpt.value()->getName() + "\":" << endl;
		for(Employee* e : emps) {
			cout << e->toString() << endl;
			delete e;
		}
	}
	delete dpt.value();
}

void Controller::showEmployeesByName(string name) {
	regex r(".*" + name + ".*");
	vector<Employee*> emps = empDAO->findAll();
	for(Employee* e : emps) {
		if (regex_match(e->getName(), r))
			showEmployee(e->getId());
		delete e;
	}
}

void Controller::showDepartmentsByName(string name) {
	regex r(".*" + name + ".*");
	vector<Department*> dpts = dptDAO->findAll();
	for(Department* d : dpts) {
		if (regex_match(d->getName(), r))
			showDepartment(d->getId());
		delete d;
	}
}

void Controller::benefitByDpt(int id) {
	cout << "Benefit of department " << id << ": " << benefitForDpt(id) << endl;
}

void Controller::totalBenefit() {
	cout << "Total benefit: " << totalBenefitForDpts() << endl;
}

// --- DB-Related public member functions ---
void Controller::showEmployee(int id) {
	optional<Employee*> e = empDAO->find(id); 
	if(e.has_value()) {
		cout << e.value()->toString() << endl;
		delete e.value();
	}
	else 
		cout << "No employee found for id: " << to_string(id) << endl;
}
optional<Employee*> Controller::findEmployee(int id) {
	return empDAO->find(id);
}
vector<Employee*> Controller::findEmployees() {
	return empDAO->findAll();
}        
void Controller::createEmployee(std::string name, int salary, int departmentId) {
	if(!checkDptId(departmentId)) throw 21;
	if(!checkSalary(salary)) throw 25;
	int id = selectEmployeeId();
	Employee employee(id, name, salary, departmentId);
	empDAO->create(employee);
	cout << "\tCreated employee succesfully" << endl;
}
void Controller::removeEmployee(int id) {
	empDAO->deletion(id);
	cout << "\tRemoved employee succesfully" << endl;
}
void Controller::updateEmployee(int id, string name, int salary, int departmentId) {
	if(!checkDptId(departmentId)) throw 21;
	if(!checkSalary(salary)) throw 25;
	Employee employee(id, name, salary, departmentId);
	empDAO->update(employee);
	cout << "\tUpdated employee succesfully" << endl;
}
optional<Department*> Controller::findDepartment(int id) {
	return dptDAO->find(id);
}
void Controller::showDepartment(int id) {
	optional<Department*> d = dptDAO->find(id); 
	if(d.has_value()) {
		cout << d.value()->toString() << endl;
		delete d.value();
	} else 
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
	cout << "\tCreated department succesfully" << endl;
}
void Controller::removeDepartment(int id) {
	dptDAO->deletion(id);
	cout << "\tRemoved department succesfully" << endl;
}
void Controller::updateDepartment(int id, string name, int sells, int managerId) {
	if(!checkManagerId(managerId)) throw 22;
	Department department(id, name, sells, managerId);
	dptDAO->update(department);
	cout << "\tUpdated department succesfully" << endl;
}

// --- Private member functions ---
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

bool Controller::checkSalary(int salary) {
	return (salary >= 0);
}

void Controller::managerMessage(Department* dpt) {
	cout << "Employee is manager of department:" << endl;
	cout << "\t" << dpt->toString() << endl;
}

void Controller::noManagerMessage() {
	cout << "Employee is not a manager" << endl;
}

optional<Employee*> Controller::managerForDpt(int dptId) {
	if(!dptDAO->idExists(dptId)) throw 23;
	optional<Department*> dpt = dptDAO->find(dptId);
	if(!dpt.has_value()) throw 23;
	optional<Employee*> emp = empDAO->find(dpt.value()->getManagerId());
	delete dpt.value();
	return emp;
}

optional<Department*> Controller::departmentForManager(int id) {
	if(!empDAO->idExists(id))
		throw 24;
	return dptDAO->departmentByManagerId(id);
}

vector<Employee*> Controller::employeesForDpt(int id) {
	vector<Employee*> emps;
	for(Employee* e : empDAO->findAll())
		if (e->getDptId() == id)
			emps.push_back(e);
		else
			delete e;
	return emps;
}

int Controller::benefitForDpt(int id) {
	int salaries = 0;
	optional<Department*> dpt = findDepartment(id);
	if (!dpt.has_value()) {
		throw 26;
	}
	vector<Employee*> emps = employeesForDpt(id);
	for(Employee* e : emps) {
		salaries += e->getSalary();
		delete e;
	}
	return dpt.value()->getSells() - salaries;
}

int Controller::totalBenefitForDpts() {
	int benefits = 0;
	vector<Department*> dpts = findDepartments();
	for(Department* dpt : dpts)
		benefits += benefitForDpt(dpt->getId());
	return benefits;
}
