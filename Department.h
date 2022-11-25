#ifndef Department_h
#define Department_h
#include <string>

class Department {
    private:
        static int id;
        std::string name;
        int sells;
        int managerId;
    public:
        Department(std::string name, int sells, int managerId);
        int getId() const;
        std::string getName() const;
        int getSells() const;
        int getManagerId() const;
        void setName(std::string name);
        void setSells(int sells);
        void setManagerId(int managerId);
        std::string to_string();
};
#endif
