#include "Helper.h"
#include "../testConstants.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <regex>
#include <fstream>
#include <cstdio>
using namespace std;

std::unordered_map<std::string, std::string> CONFIG_PARAM_MAP{{"help_file", HELP_FILE}, {"add_help_file", ADD_HELP_FILE}};

// Utility methods for test
void prepareTestFiles();
void prepareTestFile(string fileName, string content);
void removeTestFiles();
bool run_tests();
string output_result(string test_name, bool result);
void removeTestFiles();
void run_test(string test_name, bool (*test)());
bool fail();
bool assert(bool condition);
void test_result_message(bool result);
// Test methods
bool test_help();
bool test_help_command_config();
bool test_help_command_no_config();

int testCounter = 0;
int failCounter = 0;

Helper* helper;

int main() {
	prepareTestFiles();
	helper = new Helper(CONFIG_PARAM_MAP);
	test_result_message(run_tests());
    removeTestFiles();
    delete helper;
    return 0;
}

bool run_tests() {
	run_test("test_help", test_help);
	run_test("test_help_command_config", test_help_command_config);
	run_test("test_help_command_no_config", test_help_command_no_config);
    return !failCounter;
}

void run_test(string test_name, bool (*test)()) {
    testCounter++;
    cout << output_result(test_name, (*test)()) << endl;
}

string output_result(string test_name, bool result) {
    string pass_fail = (result) ? "\033[1;32mpass\033[0m" : "\033[1;31mfail\033[0m";
    return "[+] " + test_name + ": " + pass_fail;     
}

void test_result_message(bool result) {
    string message;
    if(result)
        message = "\033[1;32mSuccessful test run: " + to_string(testCounter) + " tests passed\033[0m";
    else 
        message = "\033[1;31mResult: " + to_string(failCounter) + " tests failed out of " + to_string(testCounter) + "\033[0m";
    std::cout << message << endl;
}

bool fail() {
    failCounter++;
    return false;
}

bool assert(bool condition) {
    if(!condition) return fail();
    return true;
}

bool test_help(){
	return assert(helper->help() == "help!");
}

bool test_help_command_config() {
	return (helper->help("add") == "add!");
}
bool test_help_command_no_config() {
	return (helper->help("delete") == "delete!");
}

void removeTestFiles() {
	remove(HELP_FILE.c_str());
	remove(ADD_HELP_FILE.c_str());
	remove(DELETE_HELP_FILE.c_str());
}

void prepareTestFiles() {
	prepareTestFile(HELP_FILE, "help!");
	prepareTestFile(ADD_HELP_FILE, "add!");
	prepareTestFile(DELETE_HELP_FILE, "delete!");
}

void prepareTestFile(string fileName, string content) {
	ofstream file;
	file.open(fileName, ofstream::trunc);
	file << content;
	file.close();
}

unordered_map<string, string> loadConfiguration() {
    unordered_map<string, string> config_param_map;
    string fileURL = ".config";
    ifstream file(fileURL);
    string line;
    regex r("([\\w-_]+)=([\\w.-_]*)");
    smatch m;
    while(getline(file, line)) {
        //if(line.at(0) == '#')
        //    continue;
        if(regex_search(line, m, r))
            config_param_map.insert({m[1], m[2]});
    }
    return config_param_map;
}
