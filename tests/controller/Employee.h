#ifndef Employee_h
#define Employee_h
#include <string>

// No puedo ponerlo id en static porque ya puede haber algunos cargados en la base de datos mirarlo bien o si lo pongo al menos que en el constructor se tengan en cuenta.
// Tengo que mirar como hacer la asignacion de ids, o con el counter o viendo el mayor numero de la base de datos y superandolo o algo asi.
class Employee {
    private:
        int id;
        std::string name;
        int departmentId;
    public:
        Employee(int id = 0, std::string name = "DefaultName", int departmentId = 0);
        int getId() const;
        std::string getName() const;
        int getDptId() const;
        std::string toString();
        void setName(std::string name);
        void setDptId(int departmentId);
};

#endif
