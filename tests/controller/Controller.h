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
        /**
         * Constructor. Builds Controller object using employee and department files from configuration and helper object.
        */
        Controller(std::string employeeFile, std::string departmentFile, Helper& helper);
        /**
         * Selects id for a new Employee. It returns the next value to the highest one in the database.
        */
        int selectEmployeeId();
        /**
         * Selects id for a new Department. It returns the next value to the highest one in the database.
        */
        int selectDepartmentId();
        /**
         * Checks if there is an existent employee in the database for a given id.
        */
        bool checkManagerId(int id);
        /**
         * Checks if there is an existent department in the database for a given id.
        */
        bool checkDptId(int id);
        /**
         * Checks that salary isn't negative.
        */
        bool checkSalary(int salary);
        /**
         * Indicates that the given employee is manager and shows the department.
        */
        void managerMessage(Department* dpt);
        /**
         * Indicates that the given employee is not a manager.
        */
        void noManagerMessage();
        /**
         * Returns the sells of a department minus the total salaries of it's employees.
        */
        int benefitForDpt(int id);
        /**
         * Returns the total benefit of all departments.
        */
        int totalBenefitForDpts();
        /**
         * Searches for the manager of a given department and returns it if it exists.
        */
        std::optional<Employee*> managerForDpt(int dptId);
        /**
         * Searches for the department of which the given id is manager of. 
        */
        std::optional<Department*> departmentForManager(int id);
        /**
         * Returns a list of the employees of a given department.
        */
        std::vector<Employee*> employeesForDpt(int id);
        /**
         * Returns employee with id if it exists. 
        */
        optional<Employee*> findEmployee(int id);
        /**
         * Returns list of employees.
        */
        vector<Employee*> findEmployees();     
        /**
         * Returns department with id if it exists. 
        */
        optional<Department*> findDepartment(int id);
        /**
         * Returns list of departments.
        */
        vector<Department*> findDepartments();
   
        
    public:
        Controller(Controller &other) = delete; /// Singleton objects should not be cloneable.
        /**
         * Destructor. Deletes empDAO and dptDAO objects.
        */
        ~Controller();
        /**
         * Accesor method to get instance of object. If the object hasn't already been created, it calls the 
         * constructor. If it has, it returns a reference to the object.
        */
        static Controller *getInstance(std::string employeeFile, std::string departmentFile, Helper& helper);
       
        /// Bussiness Methods

        /**
         * Displays general help.
        */
        void displayHelp();
        /**
         * Displays help for a command.
        */
        void displayHelp(std::string command);
        /**
         * List employees.
        */
        void lsEmployees();
        /**
         * List departments.
        */
        void lsDepartments();
        /**
         * Shows manager of a certain department.
        */
        void showManagerForDpt(int dptId);
        /**
         * Show if a given employee is manager.
        */
        void showIsManager(int id);
        /**
         * List employees of a given department.
        */
        void showEmployeesForDpt(int id);
        /**
         * Search for employees with a given name.
        */
        void showEmployeesByName(string name);
        /**
         * Search for departments with a given name.
        */
        void showDepartmentsByName(string name);
        /**
         * Shows benefit of a certain department.
        */
        void benefitByDpt(int id);
        /**
         * Shows combined benefit of all departments.
        */
        void totalBenefit();

        /// DB Related methods

        /**
         * Shows employee for a given id.
        */
        void showEmployee(int id);
        /**
         * Creates employee with given attributes.
        */
        void createEmployee(std::string = "DefaultName", int salary = 0, int departmentId = 0);
        /**
         * Removes employee from database.
        */
        void removeEmployee(int id);
        /**
         * Updates employee with given attributes.
        */
        void updateEmployee(int id, string name = "DefaultName", int salary = 0, int departmentId = 0);
        /**
         * Shows department for a given id.
        */
        void showDepartment(int id);
        /**
         * Creates department with given attributes.
        */
        void createDepartment(std::string name = "DefaultName", int sells = 0, int managerId = 0);
        /**
         * Removes department from database.
        */
        void removeDepartment(int id);
        /**
         * Updates department with given attributes.
        */
        void updateDepartment(int id, string name = "DefaultName", int sells = 0, int managerId = 0);

};
#endif
