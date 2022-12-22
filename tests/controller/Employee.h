#ifndef Employee_h
#define Employee_h
#include <string>

// No puedo ponerlo id en static porque ya puede haber algunos cargados en la base de datos mirarlo bien o si lo pongo al menos que en el constructor se tengan en cuenta.
// Tengo que mirar como hacer la asignacion de ids, o con el counter o viendo el mayor numero de la base de datos y superandolo o algo asi.
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
