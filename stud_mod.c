#include "header.h"

static void modify_fields(st* target) {
    char ch;
    pf("\nStep 2: Modify Field\n");
    pf("N/n : Name\n");
    pf("P/p : Percentage\n");
    pf("Enter Your Choice: ");
    sf(" %c", &ch);

    if (ch == 'N' || ch == 'n') {
        pf("Enter New Name: ");
        sf(" %29[^\n]", target->name);
        pf("Name updated successfully.\n");
    } else if (ch == 'P' || ch == 'p') {
        pf("Enter New Percentage: ");
        sf("%f", &target->mark);
        pf("Percentage updated successfully.\n");
    } else {
        pf("Invalid modification field selected.\n");
    }
}

void modify_data(st* ptr) {
    if (ptr == NULL) {
        pf("Empty list! No records available to modify.\n");
        return;
    }

    char op;
    pf("\nStep 1: Search Record\n");
    pf("R/r : Roll Number\n");
    pf("N/n : Name\n");
    pf("P/p : Percentage\n");
    pf("Enter Your Choice: ");
    sf(" %c", &op);

    if (op == 'R' || op == 'r') {
        int r;
        pf("Enter Roll Number to search: ");
        sf("%d", &r);

        st* temp = ptr;
        while (temp != NULL && temp->roll != r) {
            temp = temp->next;
        }

        if (temp == NULL) {
            pf("Record with Roll Number %d not found.\n", r);
            return;
        }
        modify_fields(temp);

    } else if (op == 'N' || op == 'n' || op == 'P' || op == 'p') {
        char s_name[30];
        float s_mark = 0.0f;
        int count = 0;

        if (op == 'N' || op == 'n') {
            pf("Enter Name to search: ");
            sf(" %29[^\n]", s_name);
        } else {
            pf("Enter Percentage to search: ");
            sf("%f", &s_mark);
        }

        pf("\nMatching Records:\n");
        pf("--------------------------------------\n");
        pf("%-10s %-15s %-10s\n", "Roll No", "Name", "Percentage");
        pf("--------------------------------------\n");

        st* temp = ptr;
        while (temp != NULL) {
            int match = 0;
            if ((op == 'N' || op == 'n') && strcmp(temp->name, s_name) == 0) {
                match = 1;
            } else if ((op == 'P' || op == 'p') && temp->mark == s_mark) {
                match = 1;
            }

            if (match) {
                pf("%-10d %-15s %-10.1f\n", temp->roll, temp->name, temp->mark);
                count++;
            }
            temp = temp->next;
        }
        pf("--------------------------------------\n");

        if (count == 0) {
            pf("No matching records found.\n");
            return;
        }

        int target_roll;
        pf("Enter Roll Number from list to modify: ");
        sf("%d", &target_roll);

        temp = ptr;
        while (temp != NULL && temp->roll != target_roll) {
            temp = temp->next;
        }

        if (temp == NULL) {
            pf("Selected Roll Number %d does not exist in the list.\n", target_roll);
            return;
        }

        modify_fields(temp);
    } else {
        pf("Invalid search option selected.\n");
    }
}
