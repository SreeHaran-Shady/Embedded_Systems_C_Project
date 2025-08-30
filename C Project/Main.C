// ---------------- THIS IS THE EXECUTABLE CODE ----------------
#include <stdio.h>
#include <string.h>

#define ROWS 10
#define COLS 4

// ---------------- ENUM for Bus Types ----------------
enum BusType { AC = 1, NON_AC, SLEEPER };

// ---------------- STRUCT for Passenger ----------------
struct Passenger {
    char name[50];
    int age;
    int seatRow;
    int seatCol;
    enum BusType type;
};

// ---------------- FUNCTION DECLARATIONS ----------------
void displaySeats(int seats[ROWS][COLS]);
void bookSeat(int seats[ROWS][COLS], struct Passenger passengers[], int *count);
void cancelSeat(int seats[ROWS][COLS], struct Passenger passengers[], int *count);
void printTicket(struct Passenger p);
void menu();

// ---------------- MAIN FUNCTION ----------------
int main() {
    int seats[ROWS][COLS] = {0};
    struct Passenger passengers[100];
    int count = 0;
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
                printf("\nExiting... Thank you for using the system!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// ---------------- Display Seating Layout ----------------
void displaySeats(int seats[ROWS][COLS]) {
    printf("\nSeating Layout (O = Available, X = Booked):\n\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(seats[i][j] == 0)
                printf("[O] ");
            else
                printf("[X] ");
        }
        printf("  <- Row %d\n", i+1);
    }
    printf("\n");
}

// ---------------- Book a Seat ----------------
void bookSeat(int seats[ROWS][COLS], struct Passenger passengers[], int *count) {
    struct Passenger p;
    int row, col, busChoice;

    printf("\nEnter passenger name: ");
    scanf("%s", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);

    printf("\nSelect Bus Type: \n");
    printf("1. AC\n2. NON-AC\n3. SLEEPER\n");
    printf("Choice: ");
    scanf("%d", &busChoice);
    p.type = (enum BusType)busChoice;

    displaySeats(seats);

    printf("\nEnter Row (1-%d): ", ROWS);
    scanf("%d", &row);
    printf("Enter Column (1-%d): ", COLS);
    scanf("%d", &col);

    row--; col--;

    if(row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if(seats[row][col] == 0) {
            seats[row][col] = 1;
            p.seatRow = row;
            p.seatCol = col;
            passengers[*count] = p;
            (*count)++;

            printf("\n Seat successfully booked!\n");
            printTicket(p);
        } else {
            printf("\nSeat already booked! Try another seat.\n");
        }
    } else {
        printf("\nInvalid seat selection!\n");
    }
}

// ---------------- Cancel a Seat ----------------
void cancelSeat(int seats[ROWS][COLS], struct Passenger passengers[], int *count) {
    char name[50];
    int found = 0;

    printf("\nEnter passenger name to cancel: ");
    scanf("%s", name);

    for(int i = 0; i < *count; i++) {
        if(strcmp(passengers[i].name, name) == 0) {
            int row = passengers[i].seatRow;
            int col = passengers[i].seatCol;
            seats[row][col] = 0;
            printf("\n Booking cancelled for %s (Row %d, Col %d)\n", name, row+1, col+1);

            
            for(int j = i; j < *count - 1; j++) {
                passengers[j] = passengers[j+1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\n No booking found under name %s\n", name);
    }
}

// ---------------- Print Ticket ----------------
void printTicket(struct Passenger p) {
    printf("\n=========== BUS TICKET ===========\n");
    printf("Passenger Name : %s\n", p.name);
    printf("Age            : %d\n", p.age);

    char *busType;
    if(p.type == AC) busType = "AC";
    else if(p.type == NON_AC) busType = "NON-AC";
    else busType = "SLEEPER";

    printf("Bus Type       : %s\n", busType);
    printf("Seat Location  : Row %d, Column %d\n", p.seatRow + 1, p.seatCol + 1);
    printf("Status         : CONFIRMED ✅\n");
    printf("=================================\n\n");
}

// ---------------- Menu ----------------
void menu() {
    printf("\n===== BUS RESERVATION MENU =====\n");
    printf("1. Display Seating Chart\n");
    printf("2. Book a Ticket\n");
    printf("3. Cancel a Ticket\n");
    printf("4. Exit\n");
    printf("================================\n");
}
