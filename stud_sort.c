#include "header.h"

static void swap_data(st* a, st* b) {
    int temp_roll = a->roll;
    a->roll = b->roll;
    b->roll = temp_roll;

    char temp_name[30];
    strcpy(temp_name, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, temp_name);

    float temp_mark = a->mark;
    a->mark = b->mark;
    b->mark = temp_mark;
}

void short_name(st* ptr) {
    if (ptr == NULL || ptr->next == NULL) {
        pf("List has fewer than two elements. Nothing to sort.\n");
        return;
    }

    int swapped;
    st* cur;
    st* lptr = NULL;

    do {
        swapped = 0;
        cur = ptr;

        while (cur->next != lptr) {
            if (strcmp(cur->name, cur->next->name) > 0) {
                swap_data(cur, cur->next);
                swapped = 1;
            }
            cur = cur->next;
        }
        lptr = cur;
    } while (swapped);

    pf("List sorted successfully by Student Name.\n");
}

void short_mark(st* ptr) {
    if (ptr == NULL || ptr->next == NULL) {
        pf("List has fewer than two elements. Nothing to sort.\n");
        return;
    }

    int swapped;
    st* cur;
    st* lptr = NULL;

    do {
        swapped = 0;
        cur = ptr;

        while (cur->next != lptr) {
            if (cur->mark > cur->next->mark) {
                swap_data(cur, cur->next);
                swapped = 1;
            }
            cur = cur->next;
        }
        lptr = cur;
    } while (swapped);

    pf("List sorted successfully by Percentage.\n");
}
