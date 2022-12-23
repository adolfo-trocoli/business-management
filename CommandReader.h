#ifndef CommandReader_h
#define CommandReader_h
// For test:
// 	1- Substitute Controller.h for mockController.h
// 	2- Move treatCommand from private to public so it can be accessed by test 
//  3- Uncomment type definition for controller
// #include "mockController.h"
#include "Controller.h"
#include "Command.h"
#include <set>
#include <unordered_map>
#include <vector>
using std::unordered_map, std::string;

// typedef mockController Controller;

class CommandReader {
	public:
		/**
		 * Constructor. Creates CommandReader using a reference to the Controller the calls should be directed to.
		*/
		CommandReader(Controller *controller);
		/**
		 * Reads command from standard input and treats it.
		*/
		void readCommand();
		/**
		 * Indicates if the user wants to exit the program. (Whether exit flag is active or not)
		*/
		bool exit() const;
	private:
		Controller* controller;
		bool exit_flag;

		/**
		 * Makes sure that the command exists, extract the arguments and select the call to controller.
		*/
		void treatCommand(std::string command);
		/**
		 * Shows error message if command does not exist, should be replaced with and exception.
		*/
		void errorMessage(std::string command);
		/**
		 * Separates words from command and returns vector containing individual words.
		*/
		std::vector<std::string> separateWords(std::string command);
		/**
		 * Selects the appropiate command reffered by first word of input.
		*/
		Command resolveCommand(std::string commandFirstWord);
		/**
		 * Exctracts arguments from user input and returns them in map form. Key is argument letter and value is argument value.
		*/
		std::unordered_map<std::string, std::string> extractArguments(std::string command);
		/**
		 * Selects controller call for given Command and passes argument map.
		*/
		void selectControllerCall(Command command_case, std::unordered_map<std::string, std::string> arguments);
		/**
		 * Returns true if command only consists of legible characters.
		*/
		bool isLegible(std::string command);

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
		void callManager(unordered_map<string, string> arguments);
		void callDpt(unordered_map<string, string> arguments);
		void callEmps(unordered_map<string, string> arguments);
		void callSearch(unordered_map<string, string> arguments);
		void callDptSearch(unordered_map<string, string> arguments);
		void callBenefit(unordered_map<string, string> arguments);
};	
#endif