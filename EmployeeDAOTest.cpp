#include "Employee.h"
#include "EmployeeDAO.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    EmployeeDAO empDAO("archivoEmpleados.txt");
    // Employee e1(19, "daigual", -50);
    // Employee e2(19, "noda", 680);
    vector<Employee> listaEmpleados = empDAO.findAll();
    for (Employee &e : listaEmpleados) {
        cout << e.toString() << endl;
    }

    // for(int i = 0; i < 20; i++) {
    //     Employee e(i, "Employee " + to_string(i), 100);
    //     empDAO.create(e);
    // }

    // Employee e(745021632, "Ernestiño", 167);
    // empDAO.update(e);
    
    return 0;
}

