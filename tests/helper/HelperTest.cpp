#include "Helper.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <regex>
#include <fstream>
#include <cstdio>
using namespace std;

void prepareTestFiles();
void prepareTestFile(string fileName, string content);
unordered_map<string, string> loadConfiguration();
void removeTestFiles();
bool runTests(Helper h);
bool testHelp(Helper h);
bool testHelp(string command, Helper h);

int main() {
	string message;
	prepareTestFiles();
	unordered_map<string, string> mapa = loadConfiguration();
	Helper h(mapa);
	if(runTests(h))
		message = "\033[1;32mSuccessful test run\033[0m";
	else 
		message = "\033[1;31mSome tests failed\033[0m";
	cout << message << endl;
	removeTestFiles();
	return 0;
}

bool runTests(Helper h) {
	if(!testHelp(h)) return false;
	if(!testHelp("add", h)) return false;
	if(!testHelp("delete", h)) return false;
	return true;
}

bool testHelp(Helper h){
	return (h.help() == "help!");
}

bool testHelp(string command, Helper h) {
	return (h.help(command) == command + "!");
}

void removeTestFiles() {
	remove(".config");
	remove("test_temp_help.txt");
	remove("test_temp_add.txt");
	remove("delete_help.txt");
}

void prepareTestFiles() {
	const string config = 
	"help_file=test_temp_help.txt\n"
	"add_help_file=test_temp_add.txt\n";
	prepareTestFile(".config", config);
	prepareTestFile("test_temp_help.txt", "help!");
	prepareTestFile("test_temp_add.txt", "add!");
	prepareTestFile("delete_help.txt", "delete!");
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
