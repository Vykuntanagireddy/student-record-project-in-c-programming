# student-record-project-in-c-programming
# Student Record Management System

A straightforward C program built to manage student records using a singly linked list[cite: 2]. All your data gets saved into and loaded from a file named "student.dat".

---

## What It Does

- **Add Student ('A' or 'a')**: Adds a new student record. The program automatically finds and assigns the lowest available positive number (1, 2, 3...) so there are never any duplicate roll numbers.
- **Delete Student ('D' or 'd')**: Delete directly by roll number, or type a student's name to view all matches and pick which one to remove.
- **Show Records ('S' or 's')**: Prints all saved students in a clean table showing Roll Number, Name, and Percentage.
- **Modify Record ('M' or 'm')**: Search for a student by roll number, name, or percentage, and easily update either their name or marks.
- **Save ('V' or 'v')**: Saves all current student records directly to "student.dat".
- **Sort List ('T' or 't')**: Organizes your list alphabetically by name or numerically by percentage.
- **Exit ('E' or 'e')**: Lets you choose whether to save your changes or quit right away.

---

## Project Files

- 'header.h': Contains the student structure definition and function prototypes.
- 'main.c': Handles the interactive menu loop and loads records on startup.
- 'stud_add.c': Takes user input and attaches new nodes to the list.
- 'stud_del.c': Removes records by roll number or name.
- 'stud_show.c': Formats and displays the student table.
- 'stud_mod.c': Finds and edits student details.
- 'stud_save.c': Reads and writes data to "student.dat".
- 'stud_sort.c': Sorts the list by name or marks.
- 'stud_util.c': Helper functions for counting, clearing memory, and reversing.
- 'Makefile': Automates compiling all files into an executable named 'student'

---

## How to Run It

1. **Compile the program:**
   ---
   make
2. **Run the executable:
    ---
   ./student
           make
2.Run the executable:
   -bash
           ./student
