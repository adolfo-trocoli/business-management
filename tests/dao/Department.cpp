#include "Department.h"
#include <string>
using namespace std;

Department::Department(int id, string name, int sells, int managerId) {
    this->id = id;
    this->name = name;
    this->sells = sells;
    this->managerId = managerId;
}
int Department::getId() const {return id;}
string Department::getName() const {return name;}
int Department::getSells() const {return sells;}
int Department::getManagerId() const {return managerId;}
void Department::setName(string name) {this->name = name;}
void Department::setSells(int sells) {this->sells = sells;}
void Department::setManagerId(int managerId) {this->managerId = managerId;}
string Department::toString() {return to_string(id) + " \"" + name + "\" " + to_string(sells) + " " + to_string(managerId);}
