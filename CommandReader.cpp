#include "CommandReader.h"
#include "Controller.h"
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

CommandReader::CommandReader(Controller *controller) {
	this->controller = controller;
}

void CommandReader::readCommand() {
	string command;
	cout << "$ ";
	cin >> command;
	treatCommand(command);
}

/**
 * Checks if a command is valid. Returns a bool value indicating the status.
 */
bool invalidCommand(string command) {
	//TODO: comprobar lo de commands.end
	bool valid = true;
	if (commands.find(command) == commands.end()) {
		cout << "Invalid <command!" << endl;
		valid = false;
	}
	return valid;
}

void treatCommand(string command){
	vector<string> words = separateWords(command);
	if invalidCommand(words[0]) return;
	unordered_map<string, string> arguments = extractArguments(command);		
}

vector<string> separateWords(string command) {
	vector<string> words;
	stringstream ss(command);
	string word;
	while (ss >> word)
		words.push_back(word);
	return words;
}

unordered_map<string, string> extractArguments(std::string command) {
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
}





