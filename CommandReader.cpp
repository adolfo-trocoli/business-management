#include "CommandReader.h"
#include "Controller.h"
#include <fstream>
#include <iostream>
#include <sstream>
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
 * Checks if a command is valid. Returns an integer value indicating the status.
 * Status: 
 * 	0 - No error.
 *  1 - Invalid command.
 *  2 - Invalid argument for command. 
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
	controller_call(words);
}

vector<string> separateWords(string command) {
	vector<string> words;
	stringstream ss(command);
	string word;
	while (ss >> word)
		words.push_back(word);
	return words;
}

bool controller_call(vector<string> words) {
}



