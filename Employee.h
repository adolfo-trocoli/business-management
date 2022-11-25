#ifndef Employee_h
#define Employee_h
#include <string>

class Employee {
    private:
        static int id;
        std::string name;
        int departmentId;
    public:
        Employee(std::string name, int departmentId);
        int getId() const;
        std::string getName() const;
        int getDptId() const;
        std::string toString();
        void setName(std::string name);
        void setDptId(int departmentId);
};

#endif
