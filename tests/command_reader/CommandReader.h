#ifndef CommandReader_h
#define CommandReader_h
// for test: Substitute Controller for mockController and treatCommand from public to private
// #include "mockController.h"
#include "Controller.h"
#include <set>
#include <unordered_map>
#include <vector>
using std::unordered_map, std::string;

// for test: Uncomment
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

// Se puede pasar los comandos por un parser que distinga los parametros y los devuelva en un mapa 
// con clave la letra del parametro y valor el valor
class CommandReader {
	public:
		CommandReader(Controller *controller);
		void readCommand();
		bool exit() const;
		
	private:
		Controller* controller;
		bool exit_flag;

		void treatCommand(std::string command);
		void errorMessage(std::string command);
		std::vector<std::string> separateWords(std::string command);
		Command resolveCommand(std::string commandFirstWord);
		std::unordered_map<std::string, std::string> extractArguments(std::string command);
		void selectControllerCall(Command command_case, std::unordered_map<std::string, std::string> arguments);

		void callDisplayHelp(unordered_map<string, string> arguments);
		void callCreateEmployee(unordered_map<string, string> arguments);
		void callCreateDepartment(unordered_map<string, string> arguments);
		bool callShowEmployee(unordered_map<string, string> arguments);
		bool callShowDepartment(unordered_map<string, string> arguments);
		bool callRemoveEmployee(unordered_map<string, string> arguments);
		bool callRemoveDepartment(unordered_map<string, string> arguments);
		bool callUpdateEmployee(unordered_map<string, string> arguments);
		bool callUpdateDepartment(unordered_map<string, string> arguments);
		void callLs(unordered_map<string, string> arguments);
		void callShow(unordered_map<string, string> arguments);
};	
#endif