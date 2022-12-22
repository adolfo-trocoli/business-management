#include <string>
#include <unordered_map>

const std::string CONFIG_FILE = "test_temp_config.txt";
const std::string HELP_FILE = "test_temp_help.txt";
const std::string ADD_HELP_FILE = "test_temp_add_help.txt";
const std::string DELETE_HELP_FILE("delete_help.txt");
const std::string EMPLOYEES_FILE("test_temp_employees.txt");
const std::string DEPARTMENTS_FILE = "test_temp_departments.txt";

const std::string CONFIG_FILE_CONTENT =
"help_file=" + HELP_FILE +
"\nemployee_file=" + EMPLOYEES_FILE +
"\ndepartment_file" + DEPARTMENTS_FILE;

const std::string DEPARTMENTS_FILE_CONTENT =
"1 \"Department 1\" 1500 101\n"
"2 \"Department 2\" 1500 102\n"
"3 \"Department 3\" 1500 7\n"
"4 \"Department 4\" 1500 104\n"
"5 \"Department 5\" 1500 105\n"
"6 \"Department 6\" 1500 106\n"
"7 \"Department 7\" 1500 107\n"
"8 \"Department 8\" 1500 108\n"
"9 \"Department 9\" 1500 109\n"
"10 \"Department 10\" 1500 110\n";

const std::string EMPLOYEES_FILE_CONTENT =
"1 \"Employee 1\" 1500 101\n"
"2 \"Employee 2\" 1500 8\n"
"3 \"Employee 3\" 1500 8\n"
"4 \"Employee 4\" 1500 8\n"
"5 \"Employee 5\" 1500 8\n"
"6 \"Employee 6\" 1500 106\n"
"7 \"Employee 7\" 1500 107\n"
"8 \"Employee 8\" 1500 108\n"
"9 \"Employee 9\" 1500 109\n"
"10 \"Employee 10\" 1500 110\n";

const std::string HELP_FILE_CONTENT = "<some help here>";

const std::string ADD_HELP_FILE_CONTENT = "<some add help here>";
