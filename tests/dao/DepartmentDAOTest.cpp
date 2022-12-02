#include "Department.h"
#include "DepartmentDAO.h"
#include "../testConstants.h"
#include <optional>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int testCounter = 0;
int failCounter = 0;

void prepareTestFile();
bool run_tests(DepartmentDAO& dptDAO);
void run_test(string test_name, DepartmentDAO& dptDAO, bool (*test)(DepartmentDAO&));
string output_result(string test_name, bool result);
bool test_find(DepartmentDAO& dptDAO);
bool test_findAll(DepartmentDAO& dptDAO);
bool test_deletion(DepartmentDAO& dptDAO);
bool test_update(DepartmentDAO& dptDAO);
bool test_create(DepartmentDAO& dptDAO);
bool test_maxId(DepartmentDAO& dptDAO);
bool test_idExists(DepartmentDAO& dptDAO);

int main() {
	prepareTestFile();
	string message;
	DepartmentDAO dptDAO(DEPARTMENTS_FILE);
	if (run_tests(dptDAO))
		message = "\033[1;32mSuccessful test run: " + to_string(testCounter) + " tests passed\033[0m";
	else 
		message = "\033[1;31mResult: " + to_string(failCounter) + " tests failed\033[0m";
	cout << message << endl;
	remove(DEPARTMENTS_FILE.c_str());
	return 0;
}

void prepareTestFile() {
	ofstream file;
	file.open(DEPARTMENTS_FILE, ofstream::trunc);
	file << DEPARTMENTS_FILE_CONTENT;
	file.close();
}

bool run_tests(DepartmentDAO& dptDAO) {
	run_test("test_find", dptDAO, test_find);
	run_test("test_findAll", dptDAO, test_findAll);
	run_test("test_deletion", dptDAO, test_deletion);
	run_test("test_update", dptDAO, test_update);
	run_test("test_create", dptDAO, test_create);
	run_test("test_maxId", dptDAO, test_maxId);
	run_test("test_idExists", dptDAO, test_idExists);
	return !failCounter;
}

void run_test(string test_name, DepartmentDAO& dptDAO, bool (*test)(DepartmentDAO&)) {
	cout << output_result(test_name, (*test)(dptDAO)) << endl;
}

string output_result(string test_name, bool result) {
	string pass_fail = (result) ? "pass" : "fail";
	return test_name + ": " + pass_fail;	 
}

bool test_find(DepartmentDAO& dptDAO) {
	testCounter++;
	bool result;
	optional<Department*> dpt = dptDAO.find(1);
	if(!dpt.has_value()) {
		failCounter++;
		return false;
	}
	result = (dpt.value()->getManagerId() == 101);
	if(!result) failCounter++;
	return result;
}

bool test_findAll(DepartmentDAO& dptDAO) {
	testCounter++;
	vector<Department*> dpts = dptDAO.findAll();
	for(int i = 1; i <= 10; i++)
		if(dpts[i-1]->getId() != i){
			cout << i << endl;
			failCounter++;
			return false;
		}
	return true;
}

bool test_deletion(DepartmentDAO& dptDAO) {
	testCounter++;
	dptDAO.deletion(1);
	optional<Department*> dpt = dptDAO.find(1);
	bool result = (!dpt.has_value());
	if(!result) failCounter++;
	return result; 
}

bool test_update(DepartmentDAO& dptDAO) {
	testCounter++;
	Department e(9, "Ernesto", 1500, 696);
	bool result;
	dptDAO.update(e);
	optional<Department*> dpt = dptDAO.find(9);
	if(!dpt.has_value()) {
		failCounter++;
		return false;
	}
	result = (dpt.value()->getManagerId() == e.getManagerId());
	if(!result) failCounter++;
	return result;
}

bool test_create(DepartmentDAO& dptDAO){
	testCounter++;
	Department e(100, "MockDepartment", 1500, 201);
	dptDAO.create(e);
	optional<Department*> dpt = dptDAO.find(100);
	bool result = (dpt.has_value());
	if(!result) failCounter++;
	return result;
}

bool test_maxId(DepartmentDAO& dptDAO) {
	testCounter++;
	bool result = (100 == dptDAO.maxId());
	if(!result) failCounter++;
	return result;
}

bool test_idExists(DepartmentDAO& dptDAO) {
	testCounter++;
	bool resultado;
	if(dptDAO.idExists(305)) {
		failCounter++;
		return false;	
	} 
	resultado = (dptDAO.idExists(100));
	if(!resultado) failCounter++;
	return resultado;
}

