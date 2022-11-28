#include "Employee.h"
#include "EmployeeDAO.h"
#include <optional>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int testCounter = 0;
int failCounter = 0;
const string tempFileName = "test_temp_file.txt";
const string fileContent =
"1 \"Employee 1\" 101\n"
"2 \"Employee 2\" 102\n"
"3 \"Employee 3\" 103\n"
"4 \"Employee 4\" 104\n"
"5 \"Employee 5\" 105\n"
"6 \"Employee 6\" 106\n"
"7 \"Employee 7\" 107\n"
"8 \"Employee 8\" 108\n"
"9 \"Employee 9\" 109\n"
"10 \"Employee 10\" 110\n";

void prepareTestFile(string fileName);
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
	prepareTestFile(tempFileName);
	string message;
	EmployeeDAO empDAO(tempFileName);
	if (run_tests(empDAO))
		message = "\033[1;32mSuccessful test run: " + to_string(testCounter) + " tests passed\033[0m";
	else 
		message = "\033[1;31mResult: " + to_string(failCounter) + " tests failed\033[0m";
	cout << message << endl;
	remove(tempFileName.c_str());
	return 0;
}

void prepareTestFile(string fileName) {
	ofstream file;
	file.open(tempFileName, ofstream::trunc);
	file << fileContent;
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
	cout << output_result(test_name, (*test)(empDAO)) << endl;
}

string output_result(string test_name, bool result) {
	string pass_fail = (result) ? "pass" : "fail";
	return test_name + ": " + pass_fail;	 
}

bool test_find(EmployeeDAO& empDAO) {
	testCounter++;
	bool result;
	optional<Employee*> emp = empDAO.find(1);
	if(!emp.has_value()) {
		failCounter++;
		return false;
	}
	result = (emp.value()->getDptId() == 101);
	if(!result) failCounter++;
	return result;
}

bool test_findAll(EmployeeDAO& empDAO) {
	testCounter++;
	vector<Employee*> emps = empDAO.findAll();
	for(int i = 1; i <= 10; i++)
		if(emps[i-1]->getId() != i){
			cout << i << endl;
			failCounter++;
			return false;
		}
	return true;
}

bool test_deletion(EmployeeDAO& empDAO) {
	testCounter++;
	empDAO.deletion(1);
	optional<Employee*> emp = empDAO.find(1);
	bool result = (!emp.has_value());
	if(!result) failCounter++;
	return result; 
}

bool test_update(EmployeeDAO& empDAO) {
	testCounter++;
	Employee e(9, "Ernesto", 696);
	bool result;
	empDAO.update(e);
	optional<Employee*> emp = empDAO.find(9);
	if(!emp.has_value()) {
		failCounter++;
		return false;
	}
	result = (emp.value()->getDptId() == e.getDptId());
	if(!result) failCounter++;
	return result;
}

bool test_create(EmployeeDAO& empDAO){
	testCounter++;
	Employee e(100, "MockEmployee", 201);
	empDAO.create(e);
	optional<Employee*> emp = empDAO.find(100);
	bool result = (emp.has_value());
	if(!result) failCounter++;
	return result;
}

bool test_maxId(EmployeeDAO& empDAO) {
	testCounter++;
	bool result = (100 == empDAO.maxId());
	if(!result) failCounter++;
	return result;
}

bool test_idExists(EmployeeDAO& empDAO) {
	testCounter++;
	bool resultado;
	if(empDAO.idExists(305)) {
		failCounter++;
		return false;	
	} 
	resultado = (empDAO.idExists(100));
	if(!resultado) failCounter++;
	return resultado;
}

