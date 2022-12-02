#include "Department.h"
#include "DepartmentDAO.h"
#include "Employee.h"
#include "EmployeeDAO.h"
#include "DAO.h"
#include "Controller.h"
#include "../testConstants.h"
// #include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <set>
#include <regex>
#include <optional>
#include <cstdio>
#include <iostream>
using namespace std;

std::unordered_map<std::string, std::string> CONFIG_PARAM_MAP{{"help_file", HELP_FILE}, {"employee_file", EMPLOYEES_FILE}, {"department_file", DEPARTMENTS_FILE}, {"add_help_file", ADD_HELP_FILE}};

unordered_map<string, string> loadConfiguration(int argc, char** argv, set<string> configs);
int testCounter = 0;
int failCounter = 0;

void prepareTestFile(string fileName, string content);
void prepareTestFiles();
void run_test(string test_name, bool (*test)());
string output_result(string test_name, bool result);
void removeTestFiles();
bool run_tests();
bool fail();
bool assert(bool condition);
void test_result_message(bool result);
bool test_displayHelp();
bool test_displayHelpCommand();
bool test_lsEmployees();
bool test_lsDepartments();
bool test_findEmployee();
bool test_findEmployees();
bool test_createEmployee();
bool test_removeEmployee();
bool test_updateEmployee();
bool test_findDepartment();
bool test_findDepartments();
bool test_createDepartment();
bool test_removeDepartment();
bool test_updateDepartment();

Controller* controller;

int main(int argc, char** argv) {
    prepareTestFiles();
    string employee_filename = CONFIG_PARAM_MAP["employee_file"];
    string department_filename = CONFIG_PARAM_MAP["department_file"];
    Helper helper(CONFIG_PARAM_MAP);
    controller = Controller::getInstance(employee_filename, department_filename, helper);
    test_result_message(run_tests());
    controller->lsDepartments();
    removeTestFiles();
    return 0;
}

void test_result_message(bool result) {
    string message;
    if(result)
        message = "\033[1;32mSuccessful test run: " + to_string(testCounter) + " tests passed\033[0m";
    else 
        message = "\033[1;31mResult: " + to_string(failCounter) + " tests failed out of " + to_string(testCounter) + "\033[0m";
    std::cout << message << endl;
}

void prepareTestFile(string fileName, string content) {
    ofstream file;
    file.open(fileName, ofstream::trunc);
    file << content;
    file.close();
}

void prepareTestFiles() {
    prepareTestFile(EMPLOYEES_FILE, EMPLOYEES_FILE_CONTENT);
    prepareTestFile(DEPARTMENTS_FILE, DEPARTMENTS_FILE_CONTENT);
    prepareTestFile(HELP_FILE, HELP_FILE_CONTENT);
    prepareTestFile(ADD_HELP_FILE, ADD_HELP_FILE_CONTENT);
    prepareTestFile(CONFIG_FILE, CONFIG_FILE_CONTENT);
}

void run_test(string test_name, bool (*test)()) {
    testCounter++;
    cout << output_result(test_name, (*test)()) << endl;
}

string output_result(string test_name, bool result) {
    string pass_fail = (result) ? "\033[1;32mpass\033[0m" : "\033[1;31mfail\033[0m";
    return "[+] " + test_name + ": " + pass_fail;     
}

void removeTestFiles() {
    remove(EMPLOYEES_FILE.c_str());
    remove(DEPARTMENTS_FILE.c_str());
    remove(HELP_FILE.c_str());
    remove(ADD_HELP_FILE.c_str());
    remove(CONFIG_FILE.c_str());
}

bool run_tests() {
    // Cuidado que run_test necesita que los metodos no tengan parametros
    run_test("test_displayHelp", test_displayHelp);
    run_test("test_displayHelpCommand", test_displayHelpCommand);
    run_test("test_lsEmployees", test_lsEmployees);
    run_test("test_lsDepartments", test_lsDepartments);
    run_test("test_findEmployee", test_findEmployee);
    run_test("test_findEmployees", test_findEmployees);
    run_test("test_createEmployee", test_createEmployee);
    run_test("test_removeEmployee", test_removeEmployee);
    run_test("test_updateEmployee", test_updateEmployee);
    run_test("test_findDepartment", test_findDepartment);
    run_test("test_findDepartments", test_findDepartments);
    run_test("test_createDepartment", test_createDepartment);
    run_test("test_removeDepartment", test_removeDepartment);
    run_test("test_updateDepartment", test_updateDepartment);
    return !failCounter;
}

bool fail() {
    failCounter++;
    return false;
}

bool assert(bool condition) {
    if(!condition) return fail();
    return true;
}

bool test_displayHelp() {
    string command_output;
    streambuf* oldCoutStreamBuf = cout.rdbuf(); // Store default output to restore later
    ostringstream strCout; // New output stream to store output in a string object
    cout.rdbuf(strCout.rdbuf()); // Changing default output for cout
    controller->displayHelp(); // Output goes to strCout
    cout.rdbuf(oldCoutStreamBuf); // restore old cout.
    command_output = strCout.str();
    return assert(command_output == "<some help here>");
}

bool test_displayHelpCommand() {
    string command_output;
    streambuf* oldCoutStreamBuf = cout.rdbuf(); // Store default output to restore later
    ostringstream strCout; // New output stream to store output in a string object
    cout.rdbuf( strCout.rdbuf() ); // Changing default output for cout
    controller->displayHelp("add"); // Output goes to strCout
    cout.rdbuf( oldCoutStreamBuf ); // Restore old cout.
    command_output = strCout.str();
    return assert(command_output == "<some add help here>");
}

bool test_lsEmployees() {
    string command_output;
    streambuf* oldCoutStreamBuf = cout.rdbuf(); // Store default output to restore later
    ostringstream strCout; // New output stream to store output in a string object
    cout.rdbuf( strCout.rdbuf() ); // Changing default output for cout
    controller->lsEmployees(); // Output goes to strCout
    cout.rdbuf( oldCoutStreamBuf ); // Restore old cout.
    command_output = strCout.str();
    return assert(command_output == EMPLOYEES_FILE_CONTENT);
}

bool test_lsDepartments() {
    string command_output;
    streambuf* oldCoutStreamBuf = cout.rdbuf(); // Store default output to restore later
    ostringstream strCout; // New output stream to store output in a string object
    cout.rdbuf( strCout.rdbuf() ); // Changing default output for cout
    controller->lsDepartments(); // Output goes to strCout
    cout.rdbuf( oldCoutStreamBuf ); // Restore old cout.
    command_output = strCout.str();
    return assert(command_output == DEPARTMENTS_FILE_CONTENT);
}

// -------------------------- Employees

bool test_findEmployee() {
    optional<Employee*> e = controller->findEmployee(10);
    if(!e.has_value()) return fail();
    return assert(e.value()->getDptId() == 110);
}

bool test_findEmployees() {
    vector<Employee*> employees = controller->findEmployees();
    for(int i = 1; i <= 10; i++)
        if(employees[i-1]->getId() != i)
            return fail();
    return true;
}

bool test_createEmployee() {
    if(controller->createEmployee("InvalidEmployee", 100)) return fail();
    controller->createEmployee("ValidEmployee", 5);
    if(!controller->findEmployee(11).has_value()) return fail();
    return assert(controller->findEmployee(11).value()->getDptId() == 5);
}

bool test_removeEmployee() {
    controller->removeEmployee(6);
    optional<Employee*> employee = controller->findEmployee(6);
    if(employee.has_value()) return fail();
    return true; 
}

bool test_updateEmployee() {
    if(controller->updateEmployee(9, "InvalidEmployee", 700)) return fail();
    if(!controller->updateEmployee(9, "ValidEmployee", 2)) return fail();
    optional<Employee*> emp = controller->findEmployee(9);
    if(!emp.has_value()) return fail();
    return assert(emp.value()->getDptId() == 2);
}

// ------------------ Departments

bool test_findDepartment() {
    optional<Department*> e = controller->findDepartment(10);
    if(!e.has_value()) return fail();
    return assert(e.value()->getManagerId() == 110);
}

bool test_findDepartments() {
    vector<Department*> departments = controller->findDepartments();
    for(int i = 1; i <= 10; i++)
        if(departments[i-1]->getId() != i) 
            return fail();
    return true;
}

bool test_createDepartment() {
    if(controller->createDepartment("InvalidDepartment", 1000, 696)) return fail();
    controller->createDepartment("ValidDepartment", 1000, 5);
    if(!controller->findDepartment(11).has_value()) return fail();
    return assert(controller->findDepartment(11).value()->getManagerId() == 5);
}

bool test_removeDepartment() {
    controller->removeDepartment(1);
    optional<Department*> department = controller->findDepartment(1);
    return assert(!department.has_value()); 
}

bool test_updateDepartment() {
    if(controller->updateDepartment(9, "DptInvalid-ManagerId", 1000, 700)) return fail();
    if(!controller->updateDepartment(9, "DptUpdateDepartment", 1000, 2)) return fail();
    controller->lsDepartments();
    optional<Department*> dpt = controller->findDepartment(9);
    if(!dpt.has_value()) return fail();
    return assert(dpt.value()->getManagerId() == 2);
}
