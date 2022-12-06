#include "mockController.h"
#include <iostream>
using namespace std;

// Mock Controller class built to be used in Helper tests

// Variables used to keep track of method calls
bool bhelp = false;
bool bhelp_c = false;
bool bshow = false;
bool bdptshow = false;
bool badd = false;
bool badd_name = false;
bool badd_dpt = false;
bool bremove = false;
bool bremove_dpt = false;
bool bup = false;
bool bup_name = false;
bool bup_dpt = false;
bool bdptadd = false;
bool bdptadd_sells = false;
bool bdptadd_manager = false;
bool bdptup = false;
bool bdptup_name = false;
bool bdptup_sells = false;
bool bdptup_manager = false;
bool bshow_emp = false;
bool bshow_dpt = false;
bool bls_emp = false;
bool bls_dpt	 = false;

// Accesor methods for variables
bool mockController::help() {return bhelp;}
bool mockController::help_c() {return bhelp_c;}
bool mockController::add() {return badd;}
bool mockController::add_name() {return badd_name;}
bool mockController::add_dpt() {return badd_dpt;}
bool mockController::remove() {return bremove;}
bool mockController::remove_dpt() {return bremove_dpt;}
bool mockController::up() {return bup;}
bool mockController::up_name() {return bup_name;}
bool mockController::up_dpt() {return bup_dpt;}
bool mockController::dptadd() {return bdptadd;}
bool mockController::dptadd_sells() {return bdptadd_sells;}
bool mockController::dptadd_manager() {return bdptadd_manager;}
bool mockController::dptup() {return bdptup;}
bool mockController::dptup_name() {return bdptup_name;}
bool mockController::dptup_sells() {return bdptup_sells;}
bool mockController::dptup_manager() {return bdptup_manager;}
bool mockController::ls_emp() {return bls_emp;}
bool mockController::ls_dpt() {return bls_dpt;}
bool mockController::show_emp() {return bshow_emp;}
bool mockController::show_dpt() {return bshow_dpt;}


// --- Singleton constructor --- 
mockController* mockController::controller = nullptr;
mockController::mockController() {};

mockController *mockController::getInstance() {
	if(controller == nullptr)
		controller = new mockController();
	return controller;
}

// --- Bussiness public member functions ---
void mockController::displayHelp() {
	bhelp = true;
}

void mockController::displayHelp(string command) {
	bhelp_c = true;
}


// --- DB-Related public member functions ---
void mockController::showEmployee(int id) {
	if(id == 30)
		bshow_emp = true; 
}

void mockController::showDepartment(int id) {
	if(id == 30)
		bshow_dpt = true; 
}

void mockController::createEmployee(std::string name, int departmentId) {
	if (name == "DefaultName" && departmentId == 0) badd = true;
	if (name == "Name" && departmentId == 0) badd_name = true; 
	if (name == "Name" && departmentId == 101) badd_dpt = true;
}
void mockController::updateEmployee(int id, string name, int departmentId) {
	if (id != 40) return;
	if (name == "DefaultName" && departmentId == 0) bup = true;
	if (name == "Name" && departmentId == 0) bup_name = true;
	if (name == "Name" && departmentId == 31) bup_dpt = true;
}
void mockController::updateDepartment(int id, string name, int sells, int managerId) {
	if(id != 40) return;
	if (name == "DefaultName" && sells == 0 && managerId == 0) bdptup = true;
	if (name == "Name" && sells == 0 && managerId == 0) bdptup_name = true;
	if (name == "Name" && sells == 3100 && managerId == 0) bdptup_sells = true;
	if (name == "Name" && sells == 3100 && managerId == 50) bdptup_manager = true;
}
void mockController::createDepartment(std::string name, int sells, int managerId) {
	if (name == "Name" && sells == 0 && managerId == 0) bdptadd = true;
	if (name == "Name" && sells == 1000 && managerId == 0) bdptadd_sells = true;
	if (name == "Name" && sells == 5000 && managerId == 505) bdptadd_manager = true;
}
void mockController::removeEmployee(int id) {
	if(id == 105)
		bremove = true;
}
void mockController::removeDepartment(int id) {
	if(id == 105)
		bremove_dpt = true;
}

// Yet to be added most features
void mockController::lsEmployees() {
	bls_emp = true;
}

void mockController::lsDepartments() {
	bls_dpt = true;
}