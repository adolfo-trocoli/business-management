#ifndef Employee_h
#define Employee_h
#include <string>

class Employee {
    private:
        int id;
        std::string name;
        int salary;
        int departmentId;
    public:
        Employee(int id = 0, std::string name = "DefaultName", int salary = 0, int departmentId = 0);
        int getId() const;
        std::string getName() const;
        void setName(std::string name = "DefaultName");
        int getSalary() const;
        void setSalary(int salary = 0);
        int getDptId() const;
        void setDptId(int departmentId = 0);
        std::string toString();
};

#endif
