#include "header.h"

void print(st* ptr) {
    if (ptr == NULL) {
        pf("\nNo records available to display.\n");
        return;
    }

    pf("\n--------------------------------------\n");
    pf("%-10s %-15s %-10s\n", "Roll No", "Name", "Percentage");
    pf("--------------------------------------\n");

    while (ptr != NULL) {
        pf("%-10d %-15s %-10.1f\n", ptr->roll, ptr->name, ptr->mark);
        ptr = ptr->next;
    }
    pf("--------------------------------------\n");
}
