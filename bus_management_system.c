#include <stdio.h>

struct Bus {
    int id;
    char name[30];
    char source[30];
    char destination[30];
    int seats;
    int booked[50];
};

int main() {
    struct Bus buses[20];
    int count = 0;
    int choice;

    do {
        printf("\n========== BUS MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Bus\n");
        printf("2. Display All Buses\n");
        printf("3. Book Seat\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter Bus ID: ");
            scanf("%d", &buses[count].id);

            printf("Enter Bus Name: ");
            scanf("%s", buses[count].name);

            printf("Enter Source: ");
            scanf("%s", buses[count].source);

            printf("Enter Destination: ");
            scanf("%s", buses[count].destination);

            printf("Enter Total Seats (max 50): ");
            scanf("%d", &buses[count].seats);

            for (int i = 0; i < buses[count].seats; i++) {
                buses[count].booked[i] = 0;
            }

            count++;
            printf("Bus Added Successfully!\n");
        }

        else if (choice == 2) {
            printf("\n------ All Buses ------\n");
            for (int i = 0; i < count; i++) {
                printf("\nBus ID: %d\n", buses[i].id);
                printf("Name: %s\n", buses[i].name);
                printf("Route: %s -> %s\n",
                       buses[i].source, buses[i].destination);
                printf("Total Seats: %d\n", buses[i].seats);

                int booked = 0;
                for (int j = 0; j < buses[i].seats; j++) {
                    if (buses[i].booked[j] == 1) {
                        booked++;
                    }
                }
                printf("Booked Seats: %d\n", booked);
            }
        }

        else if (choice == 3) {
            int bid, seat;
            printf("\nEnter Bus ID to Book Seat: ");
            scanf("%d", &bid);

            int found = -1;
            for (int i = 0; i < count; i++) {
                if (buses[i].id == bid) {
                    found = i;
                }
            }

            if (found == -1) {
                printf("Bus not found!\n");
            } else {
                printf("Enter Seat Number to Book: ");
                scanf("%d", &seat);

                if (seat < 1 || seat > buses[found].seats) {
                    printf("Invalid seat number!\n");
                } 
                else if (buses[found].booked[seat - 1] == 1) {
                    printf("Seat already booked!\n");
                } 
                else {
                    buses[found].booked[seat - 1] = 1;
                    printf("Seat %d booked successfully!\n", seat);
                }
            }
        }

    } while (choice != 0);

    printf("\nExiting Program...\n");
    return 0;
}
