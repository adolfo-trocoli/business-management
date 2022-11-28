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
        
        // Bussiness Methods
        void displayHelp();
        void displayHelp(std::string command);
        void lsEmployess();
        void lsDepartments();
        void show();

        // DB Related methods
        optional<Employee*> findEmployee(int id);
        optional<vector<Employee*>> findEmployees();        
        void createEmployee(std::string = "DefaultName", int departmentId = 0);
        void removeEmployee(int id);
        void updateEmployee(int id, string name = "DefaultName", int departmentId = 0);

        optional<Department*> findDepartment(int id);
        optional<vector<Department*>> findDepartments();
        void createDepartment(std::string name = "DefaultName", int sells = 0, int managerId = 0);
        void removeDepartment(int it);
        void updateDepartment(int id, string name = "DefaultName", int sells = 0, int managerId = 0);
};
#endif