#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pf printf
#define sf scanf
#define FILE_NAME "student.dat"

typedef struct student {
    int roll;
    char name[30];
    float mark;
    struct student *next;
} st;

/* Function Declarations */
void add_end(st** ptr);
void delete(st** ptr);
void print(st* ptr);
void modify_data(st* ptr);
void save(st* ptr);
void load(st** ptr);
void short_name(st* ptr);
void short_mark(st* ptr);
void delete_all(st** ptr);
void rev_data(st* ptr);
int count(st* ptr);

#endif
