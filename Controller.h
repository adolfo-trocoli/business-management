#ifndef Controller_h
#define Controller_h
#include <string>

/**
 * Singleton Controller used to manage CLI for program.
 * 
 */
class Controller {
    protected:
        static Controller* controller;
        std::string
        Controller();
    public:
        static Controller *getInstance();
        Employee* findEmployee(int id);
        Department* findEmployee(int id);
        Employee** findEmployees();
        Department** findDepartments();
};
