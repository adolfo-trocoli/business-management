#ifndef Controller_h
#define Controller_h
#include "Employee.h"
#include "Department.h"
#include "EmployeeDAO.h"
#include "DepartmentDAO.h"
#include "Helper.h"
#include <string>
/**
 * Singleton Controller used to manage CLI for program.
 * 
 */
class Controller {
    protected:
        static Controller* controller;
        Helper& helper;
        EmployeeDAO& empDAO;
        DepartmentDAO& dptDAO;
        Controller(std::string employeeFile, std::string departmentFile, Helper& helper);
    public:
        Controller(Controller &other) = delete; // Singleton objects should not be cloneable.
        static Controller *getInstance(std::string employeeFile, std::string departmentFile, Helper& helper);
        
        // Métodos de negocio como listar, show, calculos, etc....
        void displayHelp();
        void displayHelp(std::string command);

        void show();

        optional<Employee*> findEmployee(int id);
        optional<vector<Employee*>> findEmployees();        
        void createEmployee(std::string name, int departmentId);
        void removeEmployee(Employee employee);
        void updateEmployee(Employee employee);

        optional<Department*> findDepartment(int id);
        optional<vector<Department*>> findDepartments();
        void createDepartment(std::string name, int sells, int managerId);
        void removeDepartment(Department dpt);
        void updateDepartment(Department dpt);
};
#endif