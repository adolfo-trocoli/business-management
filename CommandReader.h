#ifndef CommandReader_h
#define CommandReader_h
#include <set>
#include <unordered_map>

// Se puede pasar los comandos por un parser que distinga los parametros y los devuelva en un mapa 
// con clave la letra del parametro y valor el valor
class CommandReader {
	public:
		CommandReader(Controller *controller);
		void readCommand();
	private:
		Controller* controller;
		const std::set<std::string> commands = 
			{
				"help",
				"add",
				"dptadd",
				"remove",
				"dptremove",
				"edit",
				"dptedit",
				"edit",
				"dptedit",
				"ls",
				"dptls",
				"show"
			};
		bool invalidOrder(std::string command);
		void errorMessage(std::string command);
		void treatCommand(std::string command);
		unordered_map<std::string, std::string> extractArguments(std::string command);
};

#endif