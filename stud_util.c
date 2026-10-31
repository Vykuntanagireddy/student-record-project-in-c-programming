#include "header.h"

int count(st* ptr) {
    int c = 0;
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    return c;
}

void delete_all(st** ptr) {
    st* temp;
    while (*ptr != NULL) {
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
}

void rev_data(st* ptr) {
    int c = count(ptr);
    if (c < 2) return;

    int size = sizeof(st) - sizeof(st*);
    st* p1 = ptr;
    st temp;

    for (int i = 0; i < c / 2; i++) {
        st* p2 = ptr;
        for (int j = 0; j < c - 1 - i; j++) {
            p2 = p2->next;
        }
        memcpy(&temp, p1, size);
        memcpy(p1, p2, size);
        memcpy(p2, &temp, size);
        p1 = p1->next;
    }
    pf("Data reversed successfully.\n");
}
