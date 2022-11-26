#include "CommandReader.h"
#include "Controller.h"
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
	cin >> command;
	treatCommand(command);
}

bool CommandReader::exit() const {return exit_flag;}

void CommandReader::treatCommand(string command){
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
	if(commandFirstWord == "dptedit") return DPTEDIT;
	if(commandFirstWord == "dptls") return DPTLS;
	if(commandFirstWord == "dptremove") return DPTREMOVE;
	if(commandFirstWord == "edit") return EDIT;
	if(commandFirstWord == "help") return HELP;
	if(commandFirstWord == "ls") return LS;
	if(commandFirstWord == "remove") return REMOVE;
	if(commandFirstWord == "show") return SHOW;
	if(commandFirstWord == "exit") return EXIT;
	if(commandFirstWord == "close") return EXIT;
	return COMMAND_ERROR;
}

unordered_map<string, string> CommandReader::extractArguments(std::string command) {
	const string s = "add -n Adolfo -d 30";
	unordered_map<string, string> hashMap;
 	vector<string> flagArgumentPairs;
    regex words_regex("-[a-zA-Z]+\\s\\w+"); 
    regex flag_argument_regex("-([a-zA-Z]+)\\s(\\w+)");
    smatch m; // Used in separation
    // Selects all matches to the regex
    auto words_begin = sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = sregex_iterator();
    // Iterates over the matches and adds them to the vector of flag-argument pairs
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;                                                 
        string match_str = match.str(); 
        flagArgumentPairs.push_back(match_str);
    } 
    // Separates the flag and the vector and stores them in the hashmap in key/value manner.
    for (string argument : flagArgumentPairs) {
    	if(regex_search(argument, m, flag_argument_regex))
    		hashMap.insert({m[1], m[2]});
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
		case(DPTDD):
			callCreateDepartment(arguments);
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
		case(DPTLS):
			callDPTLS(arguments);
			break;
		case(SHOW):
			controller->callshow(arguments);
			break;
	}
}

// Mirar si unificar los comandos de empleados y departamentos

void callDisplayHelp(unordered_map<string, string> arguments) {
	if(arguments.find("c") != arguments.end())
		controller->displayHelp(arguments["c"]);
	else
		controller->displayHelp();
}

void CommandReader::callCreateEmployee(unordered_map<string, string> arguments) {
	if(arguments.find("d") != arguments.end())
		if(arguments.find("c") != arguments.end())

}





