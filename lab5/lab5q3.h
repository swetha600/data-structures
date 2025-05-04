#include <stdio.h>
#include <stdlib.h>

class ProcessQueue {
    private:
        struct Process {
            int processTime;
            int processId;
            struct Process* next;
        }*head;
        
        static int nextProcessId; 
        int timeSlot; 
    public:
        ProcessQueue(int slot) {
            head = NULL;
            timeSlot = slot;
        }
        void insertProcess(int time);
        void execute();
        void display();
};

int ProcessQueue::nextProcessId = 0;

void ProcessQueue::insertProcess(int time) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->processTime = time;
    newProcess->processId = ++nextProcessId;

    if(head == NULL) {
        head = newProcess;
        newProcess->next = head;
        printf("Process P%d added with time %d\n", newProcess->processId, time);
        return;
    }

    struct Process* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newProcess;
    newProcess->next = head;
    printf("Process P%d added with time %d\n", newProcess->processId, time);
}

void ProcessQueue::execute() {
    if(head == NULL) {
        printf("No processes to execute!\n");
        return;
    }

    struct Process* current = head;
    int remainingTime = current->processTime - timeSlot;

    if(head->next == head) {
        if(remainingTime <= 0) {
            printf("Process P%d completed execution\n", current->processId);
            free(head);
            head = NULL;
        } else {
            head->processTime = remainingTime;
            printf("Process P%d executed for %d units. Remaining time: %d\n", 
                   current->processId, timeSlot, remainingTime);
        }
        return;
    }

    head = current->next;
    struct Process* temp = head;
    while(temp->next != current) {
        temp = temp->next;
    }
    temp->next = head;

    if(remainingTime > 0) {
        current->processTime = remainingTime;
        current->next = head;
        temp->next = current;
        printf("Process P%d executed for %d units. Remaining time: %d\n", 
               current->processId, timeSlot, remainingTime);
    } else {
        printf("Process P%d completed execution\n", current->processId);
        free(current);
    }
}

void ProcessQueue::display() {
    if(head == NULL) {
        printf("No processes in queue\n");
        return;
    }

    printf("\nCurrent Queue Status:\n");
    struct Process* temp = head;
    do {
        printf("P%d(%d) -> ", temp->processId, temp->processTime);
        temp = temp->next;
    } while(temp != head);
    printf("head\n");
}
