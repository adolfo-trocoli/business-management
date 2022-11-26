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

#define CONFIG_FILE ".config"
using namespace std;

int main(int argc, char** argv) {

    signal(SIGINT, signalHandler);
    set<string> helper_configs = {"help_file", "add_help_file"};
    set<string> db_configs = {"employee_file", "department_file"};
    unordered_map<string, string> helper_params = loadConfiguration(argc, argv, helper_configs);
    unordered_map<string, string> db_params = loadConfiguration(argc, argv, db_configs);
    
    Helper helper(helper_params);
    Controller* controller = Controller::getInstance(db_params["employee_file"], db_params["department_file"], helper);
    CommandReader reader(controller);

    string command = "";
    while (!reader.exit()) {
        reader.readCommand();        
    }
}

unordered_map<string, string> loadConfiguration(int argc, char** argv, set<string> configs) {
    unordered_map<string, string> config_param_map;
    string fileURL;
    if(argc > 1)
        fileURL = argv[1];
    else
        fileURL = CONFIG_FILE;
    ifstream file(fileURL);
    string line;
    regex r("(\\w+):(\\w*)");
    smatch m;
    while(getline(line, fileURL)) {
        if(regex_search(line, m, r))
            if(configs.find(m[1]) != configs.end())
                config_param_map.insert({m[1], m[2]})
    }
}

void signalHandler(int signum) {
   saveData();
   exit(signum);  
}

