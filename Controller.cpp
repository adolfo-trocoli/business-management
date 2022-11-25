#include "Controller.h"
#include <string>
using namespace std;

Controller::Controller() {};
static Controller *getInstance();
Employee* findEmployee(int id);
Department* findEmployee(int id);
Employee** findEmployees();
Department** findDepartments();