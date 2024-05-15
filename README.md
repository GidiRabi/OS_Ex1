# README

This README provides detailed instructions and information about various aspects of the project mostly explaining each question.
In each folder you'll find a terminal.txt file that contains a run of the program.
In questions where files were created the files are attached and viewable, screenshots are included in unsaveable files & program execution.

Run  `make all` in the main folder then follow, the instructions bellow.


## Table of Contents

- [Q1](#q1) - [Q2](#q2) - [Q3](#q3) - [Q4](#q4) - [Q5](#q5) - [Q6](#q6) - [Disclaimer](#disclaimer)

  
## Q1

In Question 1, all runs and errors/failures are documented within the terminal. Additionally, core dumped files are provided, along with a screenshot of the opened DDD (Data Display Debugger) and GDB (GNU Debugger) inside the terminal.


## Q2

A screenshot illustrating a successful run is attached. To execute, simply run the command:


```bash
make all
./poisson x y
```

## Q3

A screenshot demonstrating a successful run is provided. To execute, follow these steps:

```bash
make all
./program
```

The hardcoded values from the assignment will be utilized as specified in Q2.


## Q4

An attached **gcov** file is available, and its contents can also be viewed within the terminal at the conclusion of execution. To initiate:

```bash
make all
./dijkstra (enter any amount of numbers with spaces between each number)
```
### Example:
```bash
gidi@gidi:~/Desktop/Ass1_OS/Q4$ ./dijkstra 0 0 1
Enter values for row 2 (expected 3 values):
0 0 1
Enter values for row 3 (expected 3 values):
1 1 0
Vertex 	 Distance from Source
0 		0
1 		2
2 		1
```
If numbers are entered, the program will proceed and prompt "Enter values for row x (expected y values):" for each row. To generate the gcov:

```bash
gcov dijkstra.cpp
```


## Q5

Nine files are attached, following the naming convention: *NameOfProg_Profiling_Number*, covering three programs and three sizes. This allows for the comparison of runtime occurrences for each.

## Q6

The terminal to an example output is provided

```bash
make all
./findPhone _____
./add2PB "Full name,Phone Number"
make clean
```

### Example:
```bash
./findPhone Micky
./add2PB "nezer ofer,03-1234567"
./findPhone ofer
```


# Disclaimer

During the assignment ChatGPT was used for correcting and enhancing documentations and provided assistance in fixing C++ code where necessary + help from gal & chanan.

# Authors
* Gidi Rabi - gidirabi111@gmail.com
* Maayan sher - maayan1sher@gmail.com

