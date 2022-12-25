# bussiness-management
Simple program in c++ developed to use the basic concepts of OOP, file access and some design patterns like Singleton or Pattern.

Bussiness management app, capable of keeping register of employees, it's 
positions, salaries and other characteristics.

Every employee will have a unique id, a name, their sells, and a department.
Every department will have a name, sells data and a Manager 
associated.

The app will be able to interpret commands in a shell-like style:

help - show help menu
add - add an employee or manager
dptadd - add a department
remove - remove an employee
dptremove - remove a department
edit - edit an employee
dptedit - edit a department
ls - list all employees and its characteristics
dptls - list all departments
show - show all information in database
...


The database will be implemented using a simple text file for each kind of 
object. In a file, each object (employee or department) will be written in a 
line.
