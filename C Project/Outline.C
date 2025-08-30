// -------------------- THIS IS TO DEFINE THE OUTILE OF THE CODE NOT FOR EXECUTION --------------------

#include <stdio.h>
#include <string.h>

// -------------------- ENUMS --------------------
enum BusType { AC = 1, NON_AC, SLEEPER };

// -------------------- STRUCTS --------------------
struct Passenger {
    char name[50];
    int age;
    int seatRow;
    int seatCol;
    enum BusType type;
};

// -------------------- CONSTANTS --------------------
#define ROWS 10
#define COLS 4

// -------------------- FUNCTION DECLARATIONS --------------------
void displaySeats(int seats[ROWS][COLS]);
void bookSeat(int seats[ROWS][COLS], struct Passenger passengers[], int *count);
void cancelSeat(int seats[ROWS][COLS], struct Passenger passengers[], int *count);
void menu();

// -------------------- MAIN FUNCTION --------------------
int main() {
    int seats[ROWS][COLS] = {0};  // 0 = available, 1 = booked
    struct Passenger passengers[100]; // store passenger details
    int count = 0; // number of passengers

    int choice;

    do {
        menu();
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookSeat(seats, passengers, &count);
                break;
            case 3:
                cancelSeat(seats, passengers, &count);
                break;
            case 4:
                printf("\nExiting... Thank you!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}

// -------------------- FUNCTION DEFINITIONS --------------------

// Show seating layout
void displaySeats(int seats[ROWS][COLS]) {
    // TODO: Loop through 2D array and show O (open) / X (booked)
}

// Book a seat
void bookSeat(int seats[ROWS][COLS], struct Passenger passengers[], int *count) {
    // TODO: Ask user details + seat number
    // TODO: Check if available, then mark booked
    // TODO: Store passenger details in struct
}

// Cancel a booking
void cancelSeat(int seats[ROWS][COLS], struct Passenger passengers[], int *count) {
    // TODO: Ask for seat details or name
    // TODO: Free seat if found
}

// Display menu
void menu() {
    printf("\n===== BUS RESERVATION MENU =====\n");
    printf("1. Display Seating Chart\n");
    printf("2. Book a Ticket\n");
    printf("3. Cancel a Ticket\n");
    printf("4. Exit\n");
    printf("================================\n");
}
