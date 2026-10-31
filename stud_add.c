#include "header.h"

/* Find the smallest positive unused integer for roll number */
static int get_smallest_available_roll(st* head) {
    int candidate = 1;
    while (1) {
        int found = 0;
        st* cur = head;
        while (cur != NULL) {
            if (cur->roll == candidate) {
                found = 1;
                break;
            }
            cur = cur->next;
        }
        if (!found) {
            return candidate;
        }
        candidate++;
    }
}

void add_end(st** ptr) {
    char ch;
    do {
        st* temp = (st*)malloc(sizeof(st));
        if (temp == NULL) {
            pf("Error: Memory allocation failed!\n");
            return;
        }

        temp->roll = get_smallest_available_roll(*ptr);
        temp->next = NULL;

        pf("Assigned Roll Number: %d\n", temp->roll);
        pf("Enter Student Name: ");
        sf(" %29[^\n]", temp->name);
        pf("Enter Percentage: ");
        sf("%f", &temp->mark);

        if (*ptr == NULL) {
            *ptr = temp;
        } else {
            st* last = *ptr;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = temp;
        }

        pf("Do you want to enter another student record? (y/n): ");
        sf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
