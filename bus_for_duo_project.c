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
    char member1_name[50];
    char member2_name[50];
    char roll1[30];
    char roll2[30];
    printf("Enter Member 1 Name: ");
    fgets(member1_name, sizeof(member1_name), stdin);
    {
        int i = 0;
        while (member1_name[i] != '\0') {
            if (member1_name[i] == '\n') { member1_name[i] = '\0'; break; }
            i++;
        }
    }
    printf("Enter Member 1 Roll/ID: ");
    fgets(roll1, sizeof(roll1), stdin);
    {
        int i = 0;
        while (roll1[i] != '\0') {
            if (roll1[i] == '\n') { roll1[i] = '\0'; break; }
            i++;
        }
    }
    printf("Enter Member 2 Name: ");
    fgets(member2_name, sizeof(member2_name), stdin);
    {
        int i = 0;
        while (member2_name[i] != '\0') {
            if (member2_name[i] == '\n') { member2_name[i] = '\0'; break; }
            i++;
        }
    }
    printf("Enter Member 2 Roll/ID: ");
    fgets(roll2, sizeof(roll2), stdin);
    {
        int i = 0;
        while (roll2[i] != '\0') {
            if (roll2[i] == '\n') { roll2[i] = '\0'; break; }
            i++;
        }
    }
    do {
        printf("\n===============================================================================\n");
        printf("                       BUS MANAGEMENT SYSTEM (DUO PROJECT)   \n");
        printf("      Members: %s (%s) & %s (%s)\n",
               member1_name, roll1, member2_name, roll2);
        printf("=================================================================================\n");
        printf("1. Add Bus\n");
        printf("2. Display All Buses\n");
        printf("3. Book Seat\n");
        printf("4. Cancel Booking\n");
        printf("5. View Bus Details (seat map)\n");
        printf("6. Search Bus by ID\n");
        printf("7. Search Bus by Name (substring)\n");
        printf("8. Reset All Data (clear buses)\n");
        printf("9. Project Credits (show duo info)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }
        while (getchar() != '\n');
        if (choice == 1) {
            if (count >= 20) {
                printf("Cannot add more buses (limit reached).\n");
            } else {
                struct Bus b;
                int i;
                printf("Enter Bus ID (integer): ");
                scanf("%d", &b.id);
                while (getchar() != '\n');
                for (i = 0; i < count; i++) {
                    if (buses[i].id == b.id) break;
                }
                if (i < count) {
                    printf("A bus with ID %d already exists.\n", b.id);
                } else {
                    printf("Enter Bus Name: ");
                    fgets(b.name, sizeof(b.name), stdin);
                    for (i = 0; b.name[i] != '\0'; i++) if (b.name[i] == '\n') { b.name[i] = '\0'; break; }
                    printf("Enter Source: ");
                    fgets(b.source, sizeof(b.source), stdin);
                    for (i = 0; b.source[i] != '\0'; i++) if (b.source[i] == '\n') { b.source[i] = '\0'; break; }
                    printf("Enter Destination: ");
                    fgets(b.destination, sizeof(b.destination), stdin);
                    for (i = 0; b.destination[i] != '\0'; i++) if (b.destination[i] == '\n') { b.destination[i] = '\0'; break; }
                    printf("Enter Total Seats (max 50): ");
                    scanf("%d", &b.seats);
                    while (getchar() != '\n');
                    if (b.seats < 1 || b.seats > 50) {
                        printf("Invalid seats number. Bus not added.\n");
                    } else {
                        for (i = 0; i < b.seats; i++) b.booked[i] = 0;
                        for (i = b.seats; i < 50; i++) b.booked[i] = 0;
                        buses[count] = b;
                        count++;
                        printf("Bus added successfully!\n");
                    }
                }
            }
        }
        else if (choice == 2) {
            int i, j;
            if (count == 0) {
                printf("No buses available.\n");
            } else {
                printf("\n-------- All Buses --------\n");
                for (i = 0; i < count; i++) {
                    int booked = 0;
                    for (j = 0; j < buses[i].seats; j++) if (buses[i].booked[j] == 1) booked++;
                    printf("\nBus ID: %d\nName: %s\nRoute: %s -> %s\nSeats: %d  Booked: %d\n",
                           buses[i].id, buses[i].name, buses[i].source, buses[i].destination,
                           buses[i].seats, booked);
                }
            }
        }
        else if (choice == 3) {
            int bid, seat, i, found = -1;
            printf("Enter Bus ID to book seat: ");
            scanf("%d", &bid);
            while (getchar() != '\n');
            for (i = 0; i < count; i++) if (buses[i].id == bid) { found = i; break; }
            if (found == -1) {
                printf("Bus not found.\n");
            } else {
                printf("Enter Seat Number (1-%d): ", buses[found].seats);
                scanf("%d", &seat);
                while (getchar() != '\n');
                if (seat < 1 || seat > buses[found].seats) {
                    printf("Invalid seat number.\n");
                } else if (buses[found].booked[seat-1] == 1) {
                    printf("Seat already booked.\n");
                } else {
                    buses[found].booked[seat-1] = 1;
                    printf("Seat %d booked on Bus %d.\n", seat, buses[found].id);
                }
            }
        }
        else if (choice == 4) {
            int bid, seat, i, found = -1;
            printf("Enter Bus ID to cancel booking: ");
            scanf("%d", &bid);
            while (getchar() != '\n');
            for (i = 0; i < count; i++) if (buses[i].id == bid) { found = i; break; }
            if (found == -1) {
                printf("Bus not found.\n");
            } else {
                printf("Enter Seat Number to cancel (1-%d): ", buses[found].seats);
                scanf("%d", &seat);
                while (getchar() != '\n');
                if (seat < 1 || seat > buses[found].seats) {
                    printf("Invalid seat number.\n");
                } else if (buses[found].booked[seat-1] == 0) {
                    printf("Seat is not booked.\n");
                } else {
                    buses[found].booked[seat-1] = 0;
                    printf("Seat %d booking cancelled on Bus %d.\n", seat, buses[found].id);
                }
            }
        }
        else if (choice == 5) {
            int bid, i, j, found = -1;
            printf("Enter Bus ID to view details: ");
            scanf("%d", &bid);
            while (getchar() != '\n');
            for (i = 0; i < count; i++) if (buses[i].id == bid) { found = i; break; }
            if (found == -1) {
                printf("Bus not found.\n");
            } else {
                printf("\nBus ID: %d\nName: %s\nRoute: %s -> %s\nSeats: %d\nSeat map (0=free 1=booked):\n",
                       buses[found].id, buses[found].name, buses[found].source, buses[found].destination,
                       buses[found].seats);
                for (j = 0; j < buses[found].seats; j++) {
                    printf("%2d:%d  ", j+1, buses[found].booked[j]);
                    if ((j+1) % 8 == 0) printf("\n");
                }
                printf("\n");
            }
        }
        else if (choice == 6) {
            int bid, i, found = -1;
            printf("Enter Bus ID to search: ");
            scanf("%d", &bid);
            while (getchar() != '\n');
            for (i = 0; i < count; i++) if (buses[i].id == bid) { found = i; break; }
            if (found == -1) {
                printf("Bus not found.\n");
            } else {
                printf("Found Bus: ID:%d Name:%s Route:%s->%s Seats:%d\n",
                       buses[found].id, buses[found].name, buses[found].source, buses[found].destination,
                       buses[found].seats);
            }
        }
        else if (choice == 7) {
            char q[50];
            int i, j, matched = 0;
            printf("Enter name substring to search: ");
            fgets(q, sizeof(q), stdin);
            for (i = 0; q[i] != '\0'; i++) if (q[i] == '\n') { q[i] = '\0'; break; }
            for (i = 0; i < count; i++) {
                for (j = 0; buses[i].name[j] != '\0'; j++) {
                    int k = 0;
                    while (q[k] != '\0' && buses[i].name[j+k] != '\0' && buses[i].name[j+k] == q[k]) k++;
                    if (q[k] == '\0') { 
                        printf("Match: ID:%d Name:%s Route:%s->%s Seats:%d\n",
                               buses[i].id, buses[i].name, buses[i].source, buses[i].destination, buses[i].seats);
                        matched = 1;
                        break;
                    }
                }
            }
            if (!matched) printf("No buses matched \"%s\".\n", q);
        }
        else if (choice == 8) {
            int confirm;
            printf("Are you sure you want to clear all data? (1 = Yes, 0 = No): ");
            scanf("%d", &confirm);
            while (getchar() != '\n');
            if (confirm == 1) {
                count = 0;
                printf("All data cleared.\n");
            } else {
                printf("Reset cancelled.\n");
            }
        }
        else if (choice == 9) {
            printf("\n--- Project Credits (Duo) ---\n");
            printf("Member 1: %s   Roll/ID: %s\n", member1_name, roll1);
            printf("Member 2: %s   Roll/ID: %s\n", member2_name, roll2);
            printf("Project: Bus Management System\n");
        }
        else if (choice == 0) {
            printf("Exiting program. Goodbye!\n");
        }
        else {
            if (choice != -1) printf("Invalid option. Try again.\n");
        }
    } while (choice != 0);
    return 0;
}
