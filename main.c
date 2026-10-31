#include "header.h"

int main(void) {
    st *hptr = NULL;
    char op;

    \\ Load saved student records 
    load(&hptr);

    do {
        pf("**** STUDENT RECORD MENU ****\n");
        pf("A/a : Add New Record\n");
        pf("D/d : Delete a Record\n");
        pf("S/s : Show the List\n");
        pf("M/m : Modify a Record\n");
        pf("V/v : Save\n");
        pf("T/t : Sort the List\n");
        pf("E/e : Exit\n");
        pf("Enter Your Choice: ");
        sf(" %c", &op);

        switch (op) {
            case 'A': case 'a':
                add_end(&hptr);
                break;

            case 'D': case 'd':
                delete(&hptr);
                break;

            case 'S': case 's':
                print(hptr);
                break;

            case 'M': case 'm':
                modify_data(hptr);
                break;

            case 'V': case 'v':
                save(hptr);
                break;

            case 'T': case 't': {
                char ch_t;
                pf("\nN/n : Sort by Name\n");
                pf("P/p : Sort by Percentage\n");
                pf("Enter Your Choice: ");
                sf(" %c", &ch_t);
                if (ch_t == 'n' || ch_t == 'N') {
                    short_name(hptr);
                } else if (ch_t == 'p' || ch_t == 'P') {
                    short_mark(hptr);
                } else {
                    pf("Invalid sorting option selected.\n");
                }
                break;
            }

            case 'E': case 'e': {
                char exit_op;
                pf("\nS/s : Save and Exit\n");
                pf("E/e : Exit Without Saving\n");
                pf("Enter Your Choice: ");
                sf(" %c", &exit_op);

                if (exit_op == 's' || exit_op == 'S') {
                    save(hptr);
                    pf("Records saved. Exiting program...\n");
                } else {
                    pf("Exiting without saving...\n");
                }
                delete_all(&hptr);
                return 0;
            }

            default:
                pf("Invalid option! Please enter a valid choice.\n\n");
        }
    } while (1);

    return 0;
}
