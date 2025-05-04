#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

int main() {
    int timeSlot;
    printf("Enter the fixed time slot for Round Robin scheduling: ");
    scanf("%d", &timeSlot);

    ProcessQueue pq(timeSlot);
    int choice, processTime;

    while(1) {
        printf("\n1. Insert Process\n");
        printf("2. Execute\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter process time: ");
                scanf("%d", &processTime);
                pq.insertProcess(processTime);
                break;

            case 2:
                pq.execute();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                printf("Exiting program\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}