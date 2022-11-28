#ifndef Helper_h
#define Helper_h
#include <string>
#include <unordered_map>

class Helper {
	public:
		static const std::string HELP_FILE;
		Helper(std::unordered_map<std::string, std::string> config);
		std::string help();
		std::string help(std::string);
	private:
		std::unordered_map<std::string, std::string> config_params;
};
#endif