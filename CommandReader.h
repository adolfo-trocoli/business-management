#ifndef CommandReader_h
#define CommandReader_h
// For test:
// 	1- Substitute Controller.h for mockController.h
// 	2- Move treatCommand from private to public so it can be accessed by test 
//  3- Uncomment type definition for controller
// #include "mockController.h"
#include "Controller.h"
#include <set>
#include <unordered_map>
#include <vector>
using std::unordered_map, std::string;

// typedef mockController Controller;

enum Command {
			COMMAND_ERROR,
			EXIT,
			HELP,
			ADD,
			DPTADD,
			REMOVE,
			DPTREMOVE,
			FIND,
			DPTFIND,
			EDIT,
			DPTEDIT,
			LS,
			DPTLS,
			SHOW
};

class CommandReader {
	public:
		CommandReader(Controller *controller);
		void readCommand();
		bool exit() const;
		
		void treatCommand(std::string command);
	private:
		Controller* controller;
		bool exit_flag;

		void errorMessage(std::string command);
		std::vector<std::string> separateWords(std::string command);
		Command resolveCommand(std::string commandFirstWord);
		std::unordered_map<std::string, std::string> extractArguments(std::string command);
		void selectControllerCall(Command command_case, std::unordered_map<std::string, std::string> arguments);

		void callDisplayHelp(unordered_map<string, string> arguments);
		void callCreateEmployee(unordered_map<string, string> arguments);
		void callCreateDepartment(unordered_map<string, string> arguments);
		void callShowEmployee(unordered_map<string, string> arguments);
		void callShowDepartment(unordered_map<string, string> arguments);
		void callRemoveEmployee(unordered_map<string, string> arguments);
		void callRemoveDepartment(unordered_map<string, string> arguments);
		void callUpdateEmployee(unordered_map<string, string> arguments);
		void callUpdateDepartment(unordered_map<string, string> arguments);
		void callLs(unordered_map<string, string> arguments);
		void callShow(unordered_map<string, string> arguments);
};	
#endif