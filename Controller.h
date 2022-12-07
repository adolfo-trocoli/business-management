#ifndef Controller_h
#define Controller_h
#include "EmployeeDAO.h"
#include "DepartmentDAO.h"
#include "Helper.h"
/**
 * Singleton Controller used to manage CLI for program.
 * 
 */
class Controller {
    protected:
        static Controller* controller;
        Helper& helper;
        EmployeeDAO* empDAO;
        DepartmentDAO* dptDAO;
        Controller(std::string employeeFile, std::string departmentFile, Helper& helper);
        int selectEmployeeId();
        int selectDepartmentId();
        bool checkManagerId(int id);
        bool checkDptId(int id);
        
    public:
        Controller(Controller &other) = delete; // Singleton objects should not be cloneable.
        static Controller *getInstance(std::string employeeFile, std::string departmentFile, Helper& helper);
        
        // Bussiness Methods
        void displayHelp();
        void displayHelp(std::string command);
        void lsEmployees();
        void lsDepartments();

        // DB Related methods
        void showEmployee(int id);
        optional<Employee*> findEmployee(int id);
        vector<Employee*> findEmployees();        
        bool createEmployee(std::string = "DefaultName", int departmentId = 0);
        void removeEmployee(int id);
        bool updateEmployee(int id, string name = "DefaultName", int departmentId = 0);

        void showDepartment(int id);
        optional<Department*> findDepartment(int id);
        vector<Department*> findDepartments();
        bool createDepartment(std::string name = "DefaultName", int sells = 0, int managerId = 0);
        void removeDepartment(int id);
        bool updateDepartment(int id, string name = "DefaultName", int sells = 0, int managerId = 0);
};
#endif
