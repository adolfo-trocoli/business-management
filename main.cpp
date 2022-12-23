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

/**
 * General functions used in main program.
*/
namespace utility {
    /**
     * Loads configurations from configuration file specified in program arguments. If no configuration file is given, 
     * it defaults to ".config".
    */
    unordered_map<string, string> load_configuration(int argc, char** argv);
    /**
     * Deletes reader and controller objects.
    */
    void close_program();
    /**
     * Prints message in purple.
    */
    void printMessage(string message);
    /**
     * Manage exceptions coming from any part of the program and derives it to the specific manager function.
    */
    void manageException(int);
    /**
     * Manages DAO exceptions (1x).
    */
    void manageDAOException(int);
    /**
     * Manages controller exceptions (2x).
    */
    void manageControllerException(int);
    /**
     * Manages helper exceptions (3x).
    */
    void manageHelperException(int);
    /**
     * Manages reader exceptions (4x).
    */
    void manageReaderException(int);
}
/**
 * Signal handler for the program. Independiently of the signal received, it closes the objects in the program and then
 * exits the program with code equal to the signal received.
*/
void signalHandler(int signum);
/**
 * Enters the user interaction phase of the program, in which it reads command from standard input and interprets them.
*/
void beginInteraction();

Controller* controller;
CommandReader* reader;

int main(int argc, char** argv) {
    signal(SIGINT, signalHandler);
    unordered_map<string, string> config_params = utility::load_configuration(argc, argv);
    Helper helper(config_params);
    controller = Controller::getInstance(config_params["employee_file"], config_params["department_file"], helper);
    reader = new CommandReader(controller);
    beginInteraction();
    utility::close_program();
    return 0;
}

void beginInteraction() {
    while (!reader->exit()) {
        try {
            reader->readCommand();        
        } catch (int err) {
            utility::manageException(err);
        }
    }
}

void utility::manageException(int err) {
    int code = err % 10;
    switch(err / 10) {
        case 1:
            manageDAOException(code);
            break;
        case 2:
            manageControllerException(code);
            break;
        case 3:
            manageHelperException(code);
            break;
        case 4:
            manageReaderException(code);
            break;
    }
}

void utility::manageDAOException(int code) {
    switch(code) {
        case 1:
            printMessage("Database file doesn't exist");
            break;
        case 2:
            printMessage("No id for element deletion in database");
            break;
        case 3:
            printMessage("No id for element update in database");
            break;
    }
}

void utility::manageControllerException(int code) {
    switch(code) {
        case 1:
            printMessage("No departmentId existent in database to associate employee");
            break;
        case 2:
            printMessage("No managerId existent in database to associate department");
            break;
    }
}

void utility::manageHelperException(int code) {
    switch(code) {
        case 1:
            printMessage("No file found for general help");
            break;
        case 2:
            printMessage("No file found for command help");
            break;
    }
}

void utility::manageReaderException(int code) {
    switch(code) {
        case 1:
            printMessage("Ilegible characters in command");
            break;
        case 2:
            printMessage("Erroneus command");
            break;
        case 3:
            printMessage("Void object parsed");
            break;
        case 4:
            printMessage("Id attribute needed for command");
            break;
        case 5:
            printMessage("Additional attributes needed");
            break;
    }
}

void utility::printMessage(string message) {
    cout << "\u001b[35m" + message + "\033[0m" << endl; 
}
/**
 * Returns configuration parameters.
 */
unordered_map<string, string> utility::load_configuration(int argc, char** argv) {
    unordered_map<string, string> config_param_map;
    string config_file = (argc > 1) ? argv[1] : DEFAULT_CONFIG_FILE;
    ifstream file(config_file);
    string line;
    regex r("([\\w-_.]+)=([\\w.-_]*)");
    smatch m;
    while(getline(file, line)) {
        if(line.empty() || line.at(0) == '#')
             continue;
        if(regex_search(line, m, r))
            config_param_map.insert({m[1], m[2]});
    }
    return config_param_map;    
}

void utility::close_program() {
    delete reader;
    delete controller;
}

void signalHandler(int signum) {
   utility::close_program();
   exit(signum);  
}
