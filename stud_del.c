#include "header.h"

static void delete_by_roll(st** ptr, int roll_no) {
    st *temp = *ptr, *prev = NULL;

    while (temp != NULL && temp->roll != roll_no) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        pf("Record with Roll Number %d does not exist.\n", roll_no);
        return;
    }

    if (prev == NULL) {
        *ptr = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    pf("Record with Roll Number %d deleted successfully.\n", roll_no);
}

void delete(st** ptr) {
    if (*ptr == NULL) {
        pf("Empty list! No records available to delete.\n");
        return;
    }

    char op;
    pf("\nR/r : Delete using Roll Number\n");
    pf("N/n : Delete using Name\n");
    pf("Enter Your Choice: ");
    sf(" %c", &op);

    if (op == 'R' || op == 'r') {
        int r;
        pf("Enter Roll Number to delete: ");
        sf("%d", &r);
        delete_by_roll(ptr, r);
    } else if (op == 'N' || op == 'n') {
        char target_name[30];
        pf("Enter Name to search: ");
        sf(" %29[^\n]", target_name);

        int match_count = 0;
        st* temp = *ptr;

        pf("\nMatching Records:\n");
        pf("--------------------------------------\n");
        pf("%-10s %-15s %-10s\n", "Roll No", "Name", "Percentage");
        pf("--------------------------------------\n");

        while (temp != NULL) {
            if (strcmp(temp->name, target_name) == 0) {
                pf("%-10d %-15s %-10.1f\n", temp->roll, temp->name, temp->mark);
                match_count++;
            }
            temp = temp->next;
        }
        pf("--------------------------------------\n");

        if (match_count == 0) {
            pf("No matching records found for name \"%s\".\n", target_name);
            return;
        }

        int target_roll;
        pf("Enter the Roll Number from matching list to delete: ");
        sf("%d", &target_roll);
        delete_by_roll(ptr, target_roll);
    } else {
        pf("Invalid delete option selected.\n");
    }
}
