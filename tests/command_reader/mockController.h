#ifndef mockController_h
#define mockController_h
#include <string>
/**
 * mockController used in CommandReaderTest to manage CLI for program.
 * 
 */
typedef mockController Controller;
class mockController {
    protected:
        mockController();
        static mockController* controller;
        
    public:
        mockController(mockController &other) = delete; // Singleton objects should not be cloneable.
        static mockController *getInstance();
        
        // Flags for test
        bool help();
        bool help_c();
        bool show_emp();
        bool show_dpt();
        bool add();
        bool add_name();
        bool add_dpt();
        bool dptadd();
        bool dptadd_sells();
        bool dptadd_manager();
        bool remove();
        bool remove_dpt();
        bool up();
        bool up_name();
        bool up_dpt();
        bool dptup();
        bool dptup_name();
        bool dptup_sells();
        bool dptup_manager();
        bool ls_emp();
        bool ls_dpt();

        // Bussiness Methods
        void displayHelp();
        void displayHelp(std::string command);
        void lsEmployees();
        void lsDepartments();

        // DB Related methods
        void showEmployee(int id);
        void createEmployee(std::string = "DefaultName", int departmentId = 0);
        void removeEmployee(int id);
        void updateEmployee(int id, std::string name = "DefaultName", int = 0);

        void showDepartment(int);
        void createDepartment(std::string name = "DefaultName", int sells = 0, int managerId = 0);
        void removeDepartment(int it);
        void updateDepartment(int id, std::string name = "DefaultName", int sells = 0, int managerId = 0);
};
#endif