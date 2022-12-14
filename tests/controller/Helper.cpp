#include "Helper.h"
#include <fstream>
#include <regex>
using namespace std;

const string Helper::HELP_FILE = "help/help.txt";

/**
 * Constructor. Takes an unordered_map as a paramater to get track of the help files.
 */
Helper::Helper(unordered_map<string, string> config_params) {
	this->config_params = config_params;
}

/**
 * Shows contents of help file. If there is no "help_file" key in the configurations
 * map, the file defaults to HELP_FILE = "help.txt".
 */
string Helper::help() {
	stringstream message;
	string fileURL;
	string config_param_name = "help_file";
	if(config_params.find(config_param_name) != config_params.end())
		fileURL = config_params[config_param_name];
	else
		fileURL = HELP_FILE;
	ifstream file(fileURL);
	if (!file.good()) throw 31;
	message << file.rdbuf();
	return message.str();
}

/**
 * Shows contents of help file for a certain command. If there is no key in the
 * configurations map following the pattern "<command>_help_file", the file is by 
 * default "<command>_help.txt".
 */
string Helper::help(string command) {
	stringstream message;
	string fileURL;
	string config_param_name = command + "_help_file";
	if(config_params.find(config_param_name) != config_params.end())
		fileURL = config_params[config_param_name];
	else
		fileURL = "help/" + command + "_help.txt";
	ifstream file(fileURL);
	if (!file.good()) throw 32;
	message << file.rdbuf();
	return message.str();
}
