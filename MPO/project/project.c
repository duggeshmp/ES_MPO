#include <stdio.h>
#include <time.h>  // Include the time.h header for clock() function

#define BUS_SIZE 27
#define TRUE 0
#define FALSE -1

typedef struct Bus_Info {
    char name[10];
    short int age;
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
    if (TRUE == Bus_Full()) {
        printf("\nSeats are not available");
    } else {
        if (Rear == -1) {
            Front++;
            Rear++;
        } else {
            Rear = (Rear + 1) % BUS_SIZE;
        }
        printf("\nEnter Name: ");
        scanf("%s", bus[Rear].name);
        printf("\nEnter Age: ");
        scanf("%hd", &bus[Rear].age);
    }
}

// Function to remove a passenger (dequeue)
Bus Remove_Passenger() {
    Bus removed_passenger = {"", 0}; // Initialize an empty bus
    if (Front == -1) {
        printf("\nNo passengers to remove\n");
    } else {
        removed_passenger = bus[Front];
        if (Front == Rear) {
            Front = Rear = -1; // Queue is empty after removal
        } else {
            Front = (Front + 1) % BUS_SIZE; // Circular increment
        }
    }
    return removed_passenger;
}

// Function to return booked seats
int Booked_Seats() {
    if (Front == -1) return 0; // No passengers
    if (Rear >= Front)
        return Rear - Front + 1;
    else
        return BUS_SIZE - Front + Rear + 1;
}

// Function to return available seats
int Available_Seats() {
    return BUS_SIZE - Booked_Seats();
}

int main() {
    int choice;
    
    // Start measuring time
    clock_t start_time = clock();

    while (1) {
        printf("Enter\n");
        printf("1 for ticket Booking\n");
        printf("2 for ticket Cancel\n");
        printf("3 to check number of available seats\n");
        printf("4 to check number of booked seats\n");
        printf("any other keys to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Add_pasenger();
                break;
            case 2:
                Remove_Passenger();
                break;
            case 3:
                printf("\nAvailable Seats: %d\n", Available_Seats());
                break;
            case 4:
                printf("\nBooked Seats: %d\n", Booked_Seats());
                break;
            default:
                // End measuring time
                clock_t end_time = clock();
                double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                printf("Execution Time: %.6f seconds\n", elapsed_time);
                return 0; // Exit the program
        }
    }

    // End measuring time (if user doesn't select the default option)
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution Time: %.6f seconds\n", elapsed_time);
    return 0;
}
