#include "Employee.h"
#include "EmployeeDAO.h"
#include "../testConstants.h"
#include <optional>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

unordered_map<string, string> loadConfiguration(int argc, char** argv, set<string> configs);
void signalHandler(int signum);
int testCounter = 0;
int failCounter = 0;

void prepareTestFile();
bool run_tests(EmployeeDAO& empDAO);
void run_test(string test_name, EmployeeDAO& empDAO, bool (*test)(EmployeeDAO&));
string output_result(string test_name, bool result);
bool test_find(EmployeeDAO& empDAO);
bool test_findAll(EmployeeDAO& empDAO);
bool test_deletion(EmployeeDAO& empDAO);
bool test_update(EmployeeDAO& empDAO);
bool test_create(EmployeeDAO& empDAO);
bool test_maxId(EmployeeDAO& empDAO);
bool test_idExists(EmployeeDAO& empDAO);


int main() {
	prepareTestFile();
	string message;
	EmployeeDAO empDAO(EMPLOYEES_FILENAME);
	if (run_tests(empDAO))
		message = "\033[1;32mSuccessful test run: " + to_string(testCounter) + " tests passed\033[0m";
	else 
		message = "\033[1;31mResult: " + to_string(failCounter) + " tests failed\033[0m";
	cout << message << endl;
	remove(EMPLOYEES_FILENAME.c_str());
	return 0;
}

void prepareTestFile() {
	ofstream file;
	file.open(EMPLOYEES_FILENAME, ofstream::trunc);
	file << EMPLOYEES_FILE_CONTENT;
	file.close();
}

bool run_tests(EmployeeDAO& empDAO) {
	run_test("test_find", empDAO, test_find);
	run_test("test_findAll", empDAO, test_findAll);
	run_test("test_deletion", empDAO, test_deletion);
	run_test("test_update", empDAO, test_update);
	run_test("test_create", empDAO, test_create);
	run_test("test_maxId", empDAO, test_maxId);
	run_test("test_idExists", empDAO, test_idExists);
	return !failCounter;
}

void run_test(string test_name, EmployeeDAO& empDAO, bool (*test)(EmployeeDAO&)) {
	testCounter++;
	cout << output_result(test_name, (*test)(empDAO)) << endl;
}

string output_result(string test_name, bool result) {
	string pass_fail = (result) ? "pass" : "fail";
	return test_name + ": " + pass_fail;	 
}

bool fail() {
	failCounter++;
	return false;
}

bool test_find(EmployeeDAO& empDAO) {
	bool result;
	optional<Employee*> emp = empDAO.find(1);
	if(!emp.has_value()) return fail();
	result = (emp.value()->getDptId() == 101);
	if(!result) return fail();
	return true;
}

bool test_findAll(EmployeeDAO& empDAO) {
	vector<Employee*> emps = empDAO.findAll();
	for(int i = 1; i <= 10; i++)
		if(emps[i-1]->getId() != i){
			cout << i << endl;
			return fail();
		}
	return true;
}

bool test_deletion(EmployeeDAO& empDAO) {
	empDAO.deletion(1);
	optional<Employee*> emp = empDAO.find(1);
	bool result = (!emp.has_value());
	if(!result) return fail();
	return true; 
}

bool test_update(EmployeeDAO& empDAO) {
	Employee e(9, "Ernesto", 696);
	bool result;
	empDAO.update(e);
	optional<Employee*> emp = empDAO.find(9);
	if(!emp.has_value()) return fail();
	result = (emp.value()->getDptId() == e.getDptId());
	if(!result) return fail();
	return true;
}

bool test_create(EmployeeDAO& empDAO){
	Employee e(100, "MockEmployee", 201);
	empDAO.create(e);
	optional<Employee*> emp = empDAO.find(100);
	bool result = (emp.has_value());
	if(!result) return fail();
	return true;
}

bool test_maxId(EmployeeDAO& empDAO) {
	bool result = (100 == empDAO.maxId());
	if(!result) return fail();
	return true;
}

bool test_idExists(EmployeeDAO& empDAO) {
	bool result;
	if(empDAO.idExists(305)) return fail();
	result = (empDAO.idExists(100));
	if(!result) return fail();
	return true;
}

