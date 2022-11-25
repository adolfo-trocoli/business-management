#include "Employee.h"
#include "EmployeeDAO.h"
#include <string>
#include <fstream>
using namespace std;

EmployeeDAO::EmployeeDAO(string fileURL) : DAO(fileURL) {}

