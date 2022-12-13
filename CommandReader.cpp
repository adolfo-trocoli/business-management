#include "CommandReader.h"
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

CommandReader::CommandReader(Controller *controller) {
	this->controller = controller;
	exit_flag = false;
}

void CommandReader::readCommand() {
	string command;
	cout << "$ ";
	getline(cin, command);
	treatCommand(command);
}

bool CommandReader::exit() const {return exit_flag;}

void CommandReader::treatCommand(string command){
	if (command.empty()) return;
	vector<string> words = separateWords(command);
	Command command_case = resolveCommand(words[0]);
	switch(command_case) {
		case COMMAND_ERROR:
			errorMessage(command);
			return;
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
	if(commandFirstWord == "exit") return EXIT;
	if(commandFirstWord == "close") return EXIT;
	return COMMAND_ERROR;
}

// Por ahora no es capaz de extraer los argumentos sin valor creo, cambiarlo para el ls
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
	}
}

// Mirar si unificar los comandos de empleados y departamentos

void CommandReader::callDisplayHelp(unordered_map<string, string> arguments) {
	if(arguments.find("c") != arguments.end())
		controller->displayHelp(arguments["c"]);
	else
		controller->displayHelp();
}

void CommandReader::callCreateEmployee(unordered_map<string, string> arguments) {
	bool name = (arguments.find("n") != arguments.end());
	bool department = (arguments.find("d") != arguments.end());
	if(name) {
		if(department) {
			controller->createEmployee(arguments["n"], stoi(arguments["d"]));
		} else
			controller->createEmployee(arguments["n"]);
		return;
	} else
		controller->createEmployee();
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
	} else
		controller->createDepartment();
}

bool CommandReader::callShowEmployee(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end()) return false;
	controller->showEmployee(stoi(arguments["i"]));
	return true;
}

bool CommandReader::callShowDepartment(unordered_map<string, string> arguments) {
	if (arguments.find("i") == arguments.end()) return false;
	controller->showDepartment(stoi(arguments["i"]));
	return true;
}

bool CommandReader::callRemoveEmployee(unordered_map<string, string> arguments) {
		if (arguments.find("i") == arguments.end()) return false;
		controller->removeEmployee(stoi(arguments["i"]));
		return true;
}

bool CommandReader::callRemoveDepartment(unordered_map<string, string> arguments) {
		if (arguments.find("i") == arguments.end()) return false;
		controller->removeDepartment(stoi(arguments["i"]));
		return true;
}

bool CommandReader::callUpdateEmployee(unordered_map<string, string> arguments) {
	bool id = (arguments.find("i") != arguments.end());
	bool name = (arguments.find("n") != arguments.end());
	bool department = (arguments.find("d") != arguments.end());
	if(id) {
		if(name) {
			if(department)
				controller->updateEmployee(stoi(arguments["i"]), arguments["n"], stoi(arguments["d"]));
			else
				controller->updateEmployee(stoi(arguments["i"]), arguments["n"]);
			return true;
		} else
			controller->updateEmployee(stoi(arguments["i"]));
		return true;
	} else
		return false;
}

bool CommandReader::callUpdateDepartment(unordered_map<string, string> arguments) {
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
				return true;
			} else
				controller->updateDepartment(stoi(arguments["i"]), arguments["n"]);
			return true;
		} else 
			controller->updateDepartment(stoi(arguments["i"]));
		return true;
	} else
		return false;		
}

// Doesn't find the option yet
void CommandReader::callLs(unordered_map<string, string> arguments) {
	bool employees = (arguments.find("e") != arguments.end());
	bool departments = (arguments.find("d") != arguments.end());
	if(employees)
		controller->lsEmployees();
	if(departments)
		controller->lsDepartments();
}







