#include "CommandReader.h"
#include "mockController.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

unordered_map<string, string> loadConfiguration(int argc, char** argv, set<string> configs);

void test_result_message(bool result);
void removeObjects();
void run_test(string test_name, bool (*test)());
string output_result(string test_name, bool result);
bool run_tests();
bool fail();
bool assert(bool condition);

bool test_empty_command();
bool test_showDepartment();
bool test_showEmployee();
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

mockController* controller;
CommandReader* reader;

int main() {
    controller = mockController::getInstance();
    reader = new CommandReader(controller);
    test_result_message(run_tests());
    removeObjects();
    return 0;
}

void removeObjects() {
	delete controller;
	delete reader;
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
	run_test("test_empty_command", test_empty_command);
	run_test("test_command_error", test_command_error);
    run_test("test_displayHelp", test_displayHelp);
    run_test("test_showEmployee", test_showEmployee);
    run_test("test_showDepartment", test_showDepartment);
    run_test("test_createEmployee", test_createEmployee);
    run_test("test_createDepartment", test_createDepartment);
    run_test("test_updateEmployee", test_updateEmployee);
    run_test("test_updateDepartment", test_updateDepartment);
    run_test("test_removeEmployee", test_removeEmployee);
    run_test("test_removeDepartment", test_removeDepartment);
    run_test("test_ls", test_ls);
    run_test("test_exit", test_exit);
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

bool test_empty_command() {
	try {
		reader->treatCommand("");
	} catch(int num) {
		return assert(num == 41);
	}
	return fail();
}

bool test_command_error() {
	string command_output;
	const string reader_input = "erroneusCommand";
	streambuf* oldCoutStreamBuf = cout.rdbuf(); // Store default output to restore later
	ostringstream strCout; // New output stream to store output in a string object
	cout.rdbuf(strCout.rdbuf()); // Changing default output for cout
	reader->treatCommand(reader_input); // Output goes to strCout
	cout.rdbuf(oldCoutStreamBuf); // restore old cout.
	command_output = strCout.str();
    return assert(command_output == "Incorrect command <erroneusCommand>\n");
}

bool test_displayHelp() {
	const string help = "help";
	const string help_c = "help -c add";
	reader->treatCommand(help);
	reader->treatCommand(help_c);
	return assert(controller->help() && controller->help_c());
}

bool test_showEmployee() {
	try {
		reader->treatCommand("find");
	} catch (int err) {
		if(err != 44) return fail();
	}
	const string show_emp = "find -i 30";
	reader->treatCommand(show_emp);
	return assert(controller->show_emp());
}

bool test_showDepartment() {
	try {
		reader->treatCommand("dptfind");
	} catch (int err) {
		if(err != 44) return fail();
	}
	const string show_dpt = "dptfind -i 30";
	reader->treatCommand(show_dpt);
	return assert(controller->show_dpt());
}

bool test_createEmployee() {
	const string add = "add";
	const string name = "add -n Name";
	const string department = "add -n Name -d 101";
	try {
		reader->treatCommand(add);
	} catch (int err) {
		if(err != 43) return fail();
	}
	reader->treatCommand(name);
	reader->treatCommand(department);
	return assert(controller->add() && controller->add_name() && controller->add_dpt());
}

bool test_createDepartment() {
	const string name = "dptadd -n Name";
	const string sells = "dptadd -n Name -s 1000";
	const string managerId = "dptadd -n Name -s 5000 -m 505";
	try {
		reader->treatCommand(name);
	} catch (int err) {
		if(err != 43) return fail();
	}
	reader->treatCommand(sells);
	reader->treatCommand(managerId);
	return assert(controller->dptadd() && controller->dptadd_sells() && controller->dptadd_manager());
}
bool test_removeEmployee() {
	try {
		reader->treatCommand("remove");
	} catch (int err) {
		if(err != 44) return fail();
	}
	const string remove = "remove -i 105";
	reader->treatCommand(remove);
	return assert(controller->remove());
}
bool test_removeDepartment() {
	try {
		reader->treatCommand("dptremove");
	} catch (int err) {
		if(err != 44) return fail();
	}
	const string removeDpt = "dptremove -i 105";
	reader->treatCommand(removeDpt);
	return assert(controller->remove_dpt());
}
bool test_updateEmployee() {
	try {
		reader->treatCommand("edit");
	} catch (int err) {
		if(err != 44) return fail();
	}
	const string id = "edit -i 40";
	const string name = "edit -i 40 -n Name";
	const string dpt = "edit -i 40 -n Name -d 31";
	reader->treatCommand(id);
	reader->treatCommand(name);
	reader->treatCommand(dpt);
	return assert(controller->up() && controller->up_name() && controller->up_dpt()); 
}
bool test_updateDepartment() {
	try {
		reader->treatCommand("dptedit");
	} catch (int err) {
		if(err != 44) return fail();
	}
	const string id = "dptedit -i 40";
	const string name = "dptedit -i 40 -n Name";
	const string sells = "dptedit -i 40 -n Name -s 3100";
	const string manager = "dptedit -i 40 -n Name -s 3100 -m 50";
	reader->treatCommand(id);
	reader->treatCommand(name);
	reader->treatCommand(sells);
	reader->treatCommand(manager);
	return assert(controller->dptup() && controller->dptup_name() 
		&& controller->dptup_sells() && controller->dptup_manager()); 
}
	
bool test_ls() {
	try {
		reader->treatCommand("ls");
	} catch (int err) {
		if(err != 45) return fail();
	}
	const string ls_e = "ls -e";
	const string ls_d = "ls -d";
	reader->treatCommand(ls_e);
	reader->treatCommand(ls_d);
	return assert(controller->ls_emp() && controller->ls_dpt());
}
bool test_exit() {
	const string exit = "exit";
	if(reader->exit()) return fail();
	reader->treatCommand(exit);
	return assert(reader->exit());
}