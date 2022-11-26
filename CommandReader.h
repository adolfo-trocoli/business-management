#ifndef CommandReader_h
#define CommandReader_h
#include "Controller.h"
#include <set>
#include <unordered_map>

// Se puede pasar los comandos por un parser que distinga los parametros y los devuelva en un mapa 
// con clave la letra del parametro y valor el valor
class CommandReader {
	public:
		CommandReader(Controller *controller);
		void readCommand();
		bool exit() const;
		Controller* controller;
		bool exit_flag;

		enum Command {
			COMMAND_ERROR,
			EXIT,
			HELP,
			ADD,
			DPTADD,
			REMOVE,
			DPTREMOVE,
			EDIT,
			DPTEDIT,
			LS,
			DPTLS,
			SHOW
		};
		void errorMessage(std::string command);
		void treatCommand(std::string command);
		vector<string> separateWords(std::string command);
		Command resolveCommand(std::string commandFirstWord);
		unordered_map<std::string, std::string> extractArguments(std::string command);
		void selectControllerCall(Command command_case, unordered_map<string, string> arguments);
};

#endif