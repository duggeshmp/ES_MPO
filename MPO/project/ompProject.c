#include <stdio.h>
#include <omp.h>
#include <time.h> 
#define BUS_SIZE 27
#define TRUE 0
#define FALSE -1
#define MIN_AGE 8  // Age limit for booking a ticket

typedef struct Bus_Info {
    char name[10];
    int age;
} Bus;

Bus bus[BUS_SIZE];
int Front = -1;
int Rear = -1;

// Function to check if the bus is full
int Bus_Full() {
    if (((Front == 0) && (Rear == BUS_SIZE - 1)) || (Front == Rear + 1))
        return TRUE;
    return FALSE;
}

// Function to add a passenger (enqueue)
void Add_pasenger() {
    Bus b;

    #pragma omp critical
     {
        if (Rear == -1) {
            Front++;
            Rear++;
        } else {
        Rear = (Rear + 1) % BUS_SIZE;
        }
     }

    if (TRUE == Bus_Full()) {
        printf("\nSeats are not available\n");
    } else {
        // Ask for passenger details
        printf("\nEnter Name: ");
        scanf("%s", bus[Rear].name);
        
        // Ask for the age and check if the age is valid (at least 8 years)
        printf("\nEnter Age: ");
        scanf("%d", &bus[Rear].age);
        
        if (bus[Rear].age < MIN_AGE) {
            printf("\nSorry, the passenger must be at least %d years old to book a ticket.\n", MIN_AGE);
        } else {
             printf("\nTicket successfully booked for %s, Age: %d\n", bus[Rear].name, bus[Rear].age);
        }
    }
}

// Function to remove a passenger (dequeue)
Bus Remove_Passenger() {
    Bus removed_passenger = {"", 0}; // Initialize an empty bus
    if (Front == -1) {
        printf("\nNo passengers to remove\n");
    } else {
        #pragma omp critical
        {
            removed_passenger = bus[Front];
            if (Front == Rear) {
                Front = Rear = -1; // Queue is empty after removal
            } else {
                Front = (Front + 1) % BUS_SIZE; // Circular increment
            }
        }
    }
    return removed_passenger;
}

// Function to return booked seats
int Booked_Seats() {
    int booked = 0;
    #pragma omp parallel for reduction(+:booked)
    for (int i = 0; i < BUS_SIZE; i++) {
        if (i >= Front && i <= Rear) {
            booked++;
        }
    }
    return booked;
}

// Function to return available seats
int Available_Seats() {
    return BUS_SIZE - Booked_Seats();
}

// Function to print details of all booked passengers
void View_Booked_Passengers() {
    if (Front == -1) {
        printf("\nNo passengers are currently booked.\n");
        return;
    }

    printf("\nBooked Passengers:\n");
    #pragma omp parallel for
    for (int i = Front; i <= Rear; i = (i + 1) % BUS_SIZE) {
        #pragma omp critical
        {
            printf("\nName: %s, Age: %d\n", bus[i].name, bus[i].age);
        }
    }
}

int main() {
    int choice;

    clock_t start_time = clock();
    while (1) {
        printf("\n\nEnter\n");
        printf("1 for ticket Booking\n");
        printf("2 for ticket Cancel\n");
        printf("3 to check number of available seats\n");
        printf("4 to check number of booked seats\n");
        printf("5 to view all booked passengers\n");
        printf("any other keys to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                #pragma omp parallel
                {
                    #pragma omp single
                    Add_pasenger();
                }
                break;
            case 2:
                #pragma omp parallel
                {
                    #pragma omp single
                    Remove_Passenger();
                }
                break;
            case 3:
                printf("\nAvailable Seats: %d\n", Available_Seats());
                break;
            case 4:
                printf("\nBooked Seats: %d\n", Booked_Seats());
                break;
            case 5:
                View_Booked_Passengers();
                break;
            default:
                 clock_t end_time = clock();
                double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                printf("Execution Time: %.6f seconds\n", elapsed_time);
                
                return 0; // Exit the program
        }
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution Time: %.6f seconds\n", elapsed_time);
    return 0;
}
