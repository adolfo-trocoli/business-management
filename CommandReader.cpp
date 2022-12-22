#include "CommandReader.h"
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

/**
 * Instatiates CommandReader object.
 */
CommandReader::CommandReader(Controller *controller) {
	this->controller = controller;
	exit_flag = false;
}

// Public interface ----------------

void CommandReader::readCommand() {
	string command;
	cout << "$ ";
	getline(cin, command);
	treatCommand(command);
}

bool CommandReader::exit() const {return exit_flag;}

// Private member functions ----------------

void CommandReader::treatCommand(string command){
	if(!isLegible(command)) throw 41;
	vector<string> words = separateWords(command);
	Command command_case = resolveCommand(words[0]);
	switch(command_case) {
		case COMMAND_ERROR:
			errorMessage(command);
			break;
		case EXIT:
			exit_flag = true;
			return;
	}
	unordered_map<string, string> arguments = extractArguments(command);		
	selectControllerCall(command_case, arguments);
}

void CommandReader::errorMessage(string command) {
	cout << "Incorrect command <" << command << ">" << endl; 
}


vector<string> CommandReader::separateWords(string command) {
	vector<string> words;
	stringstream ss(command);
	string word;
	while (ss >> word)
		words.push_back(word);
	return words;
}

Command CommandReader::resolveCommand(string commandFirstWord) {
	if(commandFirstWord == "add") return ADD;
	if(commandFirstWord == "dptadd") return DPTADD;
	if(commandFirstWord == "find") return FIND;
	if(commandFirstWord == "dptfind") return DPTFIND;
	if(commandFirstWord == "edit") return EDIT;
	if(commandFirstWord == "dptedit") return DPTEDIT;
	if(commandFirstWord == "remove") return REMOVE;
	if(commandFirstWord == "dptremove") return DPTREMOVE;
	if(commandFirstWord == "help") return HELP;
	if(commandFirstWord == "ls") return LS;
	if(commandFirstWord == "manager") return MANAGER;
	if(commandFirstWord == "dpt") return DPT;
	if(commandFirstWord == "emps") return EMPS;
	if(commandFirstWord == "search") return SEARCH;
	if(commandFirstWord == "dptsearch") return DPTSEARCH;
	if(commandFirstWord == "q") return EXIT;
	if(commandFirstWord == "exit") return EXIT;
	if(commandFirstWord == "close") return EXIT;
	if(commandFirstWord == "benefit") return BENEFIT;
	return COMMAND_ERROR;
}

unordered_map<string, string> CommandReader::extractArguments(string command) {
	unordered_map<string, string> hashMap;
 	vector<string> flagArgumentPairs;
    regex words_regex("-\\w+\\s?\"?\\w*\"?[\\s\\n]*"); 
    regex flag_argument_regex("-(\\w+)\\s?\"?(\\w*)\"?");
    smatch m; // Used in separation
    // Selects all matches to the regex
    auto words_begin = sregex_iterator(command.begin(), command.end(), words_regex);
    auto words_end = sregex_iterator();
    // Iterates over the matches and adds them to the vector of flag-argument pairs
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;                                                 
        string match_str = match.str(); 
        flagArgumentPairs.push_back(match_str);
    } 
    // Separates the flag and the vector and stores them in the hashmap in key/value manner.
    for (string argument : flagArgumentPairs) {
    	if(regex_search(argument, m, flag_argument_regex)) {
    		hashMap.insert({m[1], m[2]});
    	}
    }
    return hashMap;
}		

bool CommandReader::isLegible(string command) {
	return regex_match(command, regex("[\\wñ\\s\\-_\"]*"));
}

void CommandReader::selectControllerCall(Command command_case, unordered_map<string, string> arguments) {
	switch (command_case) {
		case(HELP):
			callDisplayHelp(arguments);
			break;
		case(ADD):
			callCreateEmployee(arguments);
			break;
		case(DPTADD):
			callCreateDepartment(arguments);
			break;
		case(FIND):
			callShowEmployee(arguments);
			break;
		case(DPTFIND):
			callShowDepartment(arguments);
			break;
		case(REMOVE):
			callRemoveEmployee(arguments);
			break;
		case(DPTREMOVE):
			callRemoveDepartment(arguments);
			break;
		case(EDIT):
			callUpdateEmployee(arguments);
			break;
		case(DPTEDIT):
			callUpdateDepartment(arguments);
			break;
		case(LS):
			callLs(arguments);
			break;
		case(MANAGER):
			callManager(arguments);
			break;
		case(DPT):
			callDpt(arguments);
			break;
		case(EMPS):
			callEmps(arguments);
			break;
		case(SEARCH):
			callSearch(arguments);
			break;
		case(DPTSEARCH):
			callDptSearch(arguments);
			break;
		case(BENEFIT):
			callBenefit(arguments);
			break;
	}
}

void CommandReader::callDisplayHelp(unordered_map<string, string> arguments) {
	if(arguments.find("c") != arguments.end())
		controller->displayHelp(arguments["c"]);
	else
		controller->displayHelp();
}

void CommandReader::callCreateEmployee(unordered_map<string, string> arguments) {
	bool name = (arguments.find("n") != arguments.end());
	bool salary = (arguments.find("s") != arguments.end());
	bool department = (arguments.find("d") != arguments.end());
	if(name) {
		if(salary) {
			if(department)
				controller->createEmployee(arguments["n"], stoi(arguments["s"]), stoi(arguments["d"]));
			else
				controller->createEmployee(arguments["n"], stoi(arguments["s"]));
			return;
		} else 
			controller->createEmployee(arguments["n"]);
		return;
	} else {
		controller->createEmployee();
		throw 43;
	}
}

void CommandReader::callCreateDepartment(unordered_map<string, string> arguments) {
	bool name = (arguments.find("n") != arguments.end());
	bool sells = (arguments.find("s") != arguments.end());
	bool managerId = (arguments.find("m") != arguments.end());
	if(name) {
		if(sells) {
			if(managerId)
				controller->createDepartment(arguments["n"], stoi(arguments["s"]), stoi(arguments["m"]));
			else
				controller->createDepartment(arguments["n"], stoi(arguments["s"]));
			return;
		} else
			controller->createDepartment(arguments["n"]);
		return;
	} else {
		controller->createDepartment();
		throw 43;
	}
}

void CommandReader::callShowEmployee(unordered_map<string, string> arguments) {
	bool sells = (arguments.find("s") != arguments.end());
	if (arguments.find("i") == arguments.end()) throw 44;
	controller->showEmployee(stoi(arguments["i"]));
}

void CommandReader::callShowDepartment(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end()) throw 44;
	controller->showDepartment(stoi(arguments["i"]));
}

void CommandReader::callRemoveEmployee(unordered_map<string, string> arguments) {
		if (arguments.find("i") == arguments.end()) throw 44;
		controller->removeEmployee(stoi(arguments["i"]));
}

void CommandReader::callRemoveDepartment(unordered_map<string, string> arguments) {
		if (arguments.find("i") == arguments.end()) throw 44;
		controller->removeDepartment(stoi(arguments["i"]));
}

void CommandReader::callUpdateEmployee(unordered_map<string, string> arguments) {
	bool id = (arguments.find("i") != arguments.end());
	bool salary = (arguments.find("s") != arguments.end());
	bool name = (arguments.find("n") != arguments.end());
	bool department = (arguments.find("d") != arguments.end());
	if(id) {
		if(name) {
			if(salary) {
				if(department)
					controller->updateEmployee(stoi(arguments["i"]), arguments["n"], stoi(arguments["s"]), stoi(arguments["d"]));
				else
					controller->updateEmployee(stoi(arguments["i"]), arguments["n"], stoi(arguments["s"]));
				return;
			} else
				controller->updateEmployee(stoi(arguments["i"]), arguments["n"]);
			return;
		} else
			controller->updateEmployee(stoi(arguments["i"]));
	} else
		throw 44;
}

 void CommandReader::callUpdateDepartment(unordered_map<string, string> arguments) {
	bool id = (arguments.find("i") != arguments.end());
	bool name = (arguments.find("n") != arguments.end());
	bool sells = (arguments.find("s") != arguments.end());
	bool managerId = (arguments.find("m") != arguments.end());
	if(id) {
		if(name) {
			if(sells) {
				if(managerId)
					controller->updateDepartment(stoi(arguments["i"]), arguments["n"], stoi(arguments["s"]), stoi(arguments["m"]));
				else
					controller->updateDepartment(stoi(arguments["i"]), arguments["n"], stoi(arguments["s"]));
			} else
				controller->updateDepartment(stoi(arguments["i"]), arguments["n"]);
		} else 
			controller->updateDepartment(stoi(arguments["i"]));
	} else
		throw 44;		
}

void CommandReader::callLs(unordered_map<string, string> arguments) {
	bool employees = (arguments.find("e") != arguments.end());
	bool departments = (arguments.find("d") != arguments.end());
	if(employees)
		controller->lsEmployees();
	if(departments)
		controller->lsDepartments();
	if(!employees && !departments) throw 45;
}

void CommandReader::callManager(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end()) throw 44;
	controller->showManagerForDpt(stoi(arguments["i"]));
}

void CommandReader::callDpt(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end()) throw 44;
	controller->showIsManager(stoi(arguments["i"]));
}

void CommandReader::callEmps(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end()) throw 44;
	controller->employeesForDpt(stoi(arguments["i"]));
}

void CommandReader::callSearch(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end()) throw 44;
	controller->showEmployeesByName(arguments["n"]);
}

void CommandReader::callDptSearch(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end()) throw 44;
	controller->showDepartmentsByName(arguments["n"]);
}

void CommandReader::callBenefit(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end())
		controller->totalBenefit();
	else
		controller->benefitByDpt(stoi(arguments["i"]));
}

