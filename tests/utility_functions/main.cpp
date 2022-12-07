#include "Department.h"
#include "DepartmentDAO.h"
#include "Employee.h"
#include "EmployeeDAO.h"
#include "DAO.h"
#include "Controller.h"
#include "CommandReader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <set>
#include <regex>
#include <csignal>
using namespace std;

const string DEFAULT_CONFIG_FILE = ".config";

namespace utility {
    unordered_map<string, string> load_configuration(int argc, char** argv);
    void close_program();
}
void signalHandler(int signum);


int main(int argc, char** argv) {

    signal(SIGINT, signalHandler);
    set<string> db_configs = {"employee_file", "department_file"};
    unordered_map<string, string> config_params = utility::load_configuration(argc, argv);
    
    Helper helper(config_params);
    Controller* controller = Controller::getInstance(config_params["employee_file"], config_params["department_file"], helper);
    CommandReader reader(controller);

    while (!reader.exit()) {
        reader.readCommand();        
    }
    return 0;
}

/**
 * Returns all configurations.
 */
unordered_map<string, string> utility::load_configuration(int argc, char** argv) {
    unordered_map<string, string> config_param_map;
    string config_file = (argc > 1) ? argv[1] : DEFAULT_CONFIG_FILE;
    ifstream file(config_file);
    string line;
    regex r("([\\w-_.]+)=([\\w.-_]*)");
    smatch m;
    while(getline(file, line)) {
        if(line.at(0) == '#')
            continue;
        if(regex_search(line, m, r))
            config_param_map.insert({m[1], m[2]});
    }
    return config_param_map;    
}

void utility::close_program() {

}

void signalHandler(int signum) {
   utility::close_program();
   exit(signum);  
}



