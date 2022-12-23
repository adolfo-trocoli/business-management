#ifndef Helper_h
#define Helper_h
#include <string>
#include <unordered_map>

/**
 * Class used to encapsulate help needs in program.
*/
class Helper {
	public:
		/**
		 * Default help file. Value is "help/help.txt".
		*/
		static const std::string HELP_FILE;
		/**
		 * Constructor. Builds Helper object based on config parameters of the program.
		*/
		Helper(std::unordered_map<std::string, std::string> config);
		/**
		 * Returns general help.
		*/
		std::string help();
		/**
		 * Returns help for a command. It first searches for a file in the configuration parameters. If there is none,
		 * it uses "help/<command>_help.txt".
		*/
		std::string help(std::string);
	private:
		std::unordered_map<std::string, std::string> config_params;
};
#endif