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
using namespace std;

const string DEFAULT_CONFIG_FILE = ".config"
unordered_map<string, string> loadConfiguration(int argc, char** argv, set<string> configs);
void signalHandler(int signum);


int main(int argc, char** argv) {

    signal(SIGINT, signalHandler);
    set<string> db_configs = {"employee_file", "department_file"};
    unordered_map<string, string> config_params = loadConfiguration(argc, argv);
    
    Helper helper(helper_params);
    Controller* controller = Controller::getInstance(config_params["employee_file"], config_params["department_file"], helper);
    CommandReader reader(controller);

    for(auto kv:helper_params){
        cout << "Clave: " << kv.first << "\t";
        cout << "Valor: " << kv.second << endl;
    }

    cout << "---" << endl;

    for(auto kv:db_params){
        cout << "Clave: " << kv.first << "\t";
        cout << "Valor: " << kv.second << endl;
    }

    while (!reader.exit()) {
        reader.readCommand();        
    }
}

/**
 * Returns all configurations.
 */
unordered_map<string, string> loadConfiguration(int argc, char** argv) {
    unordered_map<string, string> config_param_map;
    string config_file;
    config_file = (argc > 1) ? argv[1] : DEFAULT_CONFIG_FILE;
    ifstream file(config_file);
    string line;
    regex r("([\\w-_.]+)=([\\w.-_]*)");
    smatch m;
    while(getline(line, config_file)) {
        if(line.at(0) == '#')
            continue;
        if(regex_search(line, m, r))
            config_param_map.insert({m[1], m[2]})
    }
}

void signalHandler(int signum) {
   saveData();
   exit(signum);  
}

