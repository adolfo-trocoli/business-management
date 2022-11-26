#ifndef Controller_h
#define Controller_h
#include "Employee.h"
#include "Department.h"
#include "EmployeeDAO.h"
#include "DepartmentDAO.h"
#include <string>
/**
 * Singleton Controller used to manage CLI for program.
 * 
 */
class Controller {
    protected:
        static Controller* controller;
        EmployeeDAO& empDAO;
        DepartmentDAO& dptDAO;
        Controller(std::string s);
    public:
        Controller(Controller &other) = delete; // Singleton objects should not be cloneable.
        static Controller *getInstance(const std::string value);
        
        
        
        optional<Employee*> findEmployee(int id);
        optional<Employee**> findEmployees();        
        void createEmployee(std::string name, int departmentId);
        void removeEmployee(Employee employee);
        void updateEmployee(Employee employee);

        optional<Department*> findDepartment(int id);
        optional<Department**> findDepartments();
        void createDepartment(std::string name, int sells, int managerId);
        void removeDepartment(Department dpt);
        void updateDepartment(Department dpt);
    };
#endif