#include "header.h"

void save(st* ptr) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        pf("Error: Unable to open %s for saving!\n", FILE_NAME);
        return;
    }

    int count = 0;
    while (ptr != NULL) {
        fprintf(fp, "%d %s %f\n", ptr->roll, ptr->name, ptr->mark);
        count++;
        ptr = ptr->next;
    }

    fclose(fp);
    pf("Successfully saved %d records to %s.\n", count, FILE_NAME);
}

void load(st** ptr) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        return; /* student.dat will be created on first save */
    }

    int roll;
    char name[30];
    float mark;
    st* last = NULL;

    while (fscanf(fp, "%d %29s %f", &roll, name, &mark) == 3) {
        st* temp = (st*)malloc(sizeof(st));
        if (temp == NULL) {
            pf("Memory allocation error while loading %s.\n", FILE_NAME);
            break;
        }

        temp->roll = roll;
        strncpy(temp->name, name, sizeof(temp->name) - 1);
        temp->name[sizeof(temp->name) - 1] = '\0';
        temp->mark = mark;
        temp->next = NULL;

        if (*ptr == NULL) {
            *ptr = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    fclose(fp);
}
