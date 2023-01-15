# Business management
> Showcase project built from scratch to demonstrate OOP features for Object Oriented Programming subject in Politechnika Krakowska.

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features)
* [Screenshots](#screenshots)
* [Setup](#setup)
* [Usage](#usage)
* [Project Status](#project-status)
* [Room for Improvement](#room-for-improvement)
* [Acknowledgements](#acknowledgements)
* [Contact](#contact)


## General Information
- C++ program designed to showcase the functionality of OOP. It represents a simple business in which there are departments and employees. It has a shell-like command line interface through which the user is able to manage objects and apply business logic to them. It mocks a database by using text files and admits configuration for both database files and help files.

## Features
- Modular file storage.
- Simple, fast database access.
- Complete set of tests for every class and functionality.

## Screenshots
![Example screenshot](./img/screenshot.png)
<!-- If you have screenshots you'd like to share, include them here. -->


## Setup
##### Binary installation
There is a fully working, pre-compiled executable called business-manager ready to download and run.

##### Compilation from source code.
- All code needed for compilation is included in primary directory. There are no libraries involved other than *C++ std*.
- There is only need to compile *.cpp* files in primary directory. Other classes are for testing purposes.

##### Compilation with test suite
- Tests are compiled independiently from their own directory.
- Every test depends on *./tests/testConstants.h* to work.
- There are symbolic links to program files to make possible the compilation with one simple command from inside the test directory.
- Tests for EmployeeDAO and DepartmentDAO classes are in the same folder but they should not be compiled together.

## Usage
How does one go about using it?
Provide various use cases and code examples here.

`write-your-code-here`

## Room for Improvement
- Output parsing responsibility should be moved from Controller class to a new one.
- Common part from Test classes should be abstracted to AbstractTest to avoid code repetition.
- Command and argument interpretation are too strongly tied to CommandReader internal functions, they could be made more modular to avoid work while adding new functions for the program.

#### Technologies Used
- C++20

#### Project Status
Project is complete. Any additions, comments and requests are welcomed in the Issues page, which will be reviewed periodically.

#### Acknowledgements
- This program was created as a final project for Object Oriented Programming subject during Erasmus+ program in Politechnika Krakowsa.
- Responsible teacher for subject: Paweł Król


#### Contact
Created by [@adolfo-trocoli](github.com/adolfo-trocoli)
LinkedIn [profile](https://www.linkedin.com/in/adolfo-trocol%C3%AD-naranjo-a07250224)

