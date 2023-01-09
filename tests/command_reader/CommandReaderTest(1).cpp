#include "CommandReader.h"
#include "mockController.h"
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

unordered_map<string, string> loadConfiguration(int argc, char** argv, set<string> configs);

void run_test(string test_name, bool (*test)());
string output_result(string test_name, bool result);
bool run_tests();
bool fail();
bool assert(bool condition);

bool test_command_error();
bool test_displayHelp();
bool test_createEmployee();
bool test_createDepartment();
bool test_removeEmployee();
bool test_removeDepartment();
bool test_updateEmployee();
bool test_updateDepartment();
bool test_ls();
bool test_show();
bool test_exit();

int testCounter = 0;
int failCounter = 0;

Controller* controller;
CommandReader* reader;

int main() {
    controller = Controller::getInstance();
    reader = new Reader(controller);
    test_result_message(run_tests());
    return 0;
}

void test_result_message(bool result) {
    string message;
    if(result)
        message = "\033[1;32mSuccessful test run: " + to_string(testCounter) + " tests passed\033[0m";
    else 
        message = "\033[1;31mResult: " + to_string(failCounter) + " tests failed out of " + to_string(testCounter) + "\033[0m";
    cout << message << endl;
}

void run_test(string test_name, bool (*test)()) {
    testCounter++;
    cout << output_result(test_name, (*test)()) << endl;
}

string output_result(string test_name, bool result) {
    string pass_fail = (result) ? "\033[1;32mpass\033[0m" : "\033[1;31mfail\033[0m";
    return "[+] " + test_name + ": " + pass_fail;     
}

bool run_tests() {
    // Cuidado que run_test necesita que los metodos no tengan parametros
    run_test("test_displayHelp", test_displayHelp);
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

bool test_command_error() {

}
bool test_displayHelp();
bool test_createEmployee();
bool test_createDepartment();
bool test_removeEmployee();
bool test_removeDepartment();
bool test_updateEmployee();
bool test_updateDepartment();
bool test_ls();
bool test_show();
bool test_exit();