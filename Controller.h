#ifndef Controller_h
#define Controller_h
#include "EmployeeDAO.h"
#include "DepartmentDAO.h"
#include "Helper.h"

// For testing:
// 1 - Change from private to public: managerForDpt, departmentForManager, employeesForDpt 

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
        void managerMessage(Department* dpt);
        void noManagerMessage();
        
    public:
        Controller(Controller &other) = delete; // Singleton objects should not be cloneable.
        static Controller *getInstance(std::string employeeFile, std::string departmentFile, Helper& helper);
        
        std::optional<Employee*> managerForDpt(int dptId);
        std::optional<Department*> departmentForManager(int id);
        std::vector<Employee*> employeesForDpt(int id);
       
        // Bussiness Methods
        void displayHelp();
        void displayHelp(std::string command);
        void lsEmployees();
        void lsDepartments();
        void showManagerForDpt(int dptId);
        void showIsManager(int id);
        void showEmployeesForDpt(int id);
        void showEmployeesByName(string name);
        void showDepartmentsByName(string name);

        // DB Related methods
        void showEmployee(int id);
        optional<Employee*> findEmployee(int id);
        vector<Employee*> findEmployees();        
        void createEmployee(std::string = "DefaultName", int departmentId = 0);
        void removeEmployee(int id);
        void updateEmployee(int id, string name = "DefaultName", int departmentId = 0);

        void showDepartment(int id);
        optional<Department*> findDepartment(int id);
        vector<Department*> findDepartments();
        void createDepartment(std::string name = "DefaultName", int sells = 0, int managerId = 0);
        void removeDepartment(int id);
        void updateDepartment(int id, string name = "DefaultName", int sells = 0, int managerId = 0);
};
#endif
