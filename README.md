🚌 Bus Management System (C Language)

A simple, menu-driven Bus Management System built using the C programming language.
This project is designed for college practicals and beginners, focusing on core C concepts like structures, arrays, loops, and conditional statements.

👥 Team Members (Duo Project)
Sparsh Srivastava — SAP ID: 590022251


📌 Project Overview

In daily life, managing buses, routes, and seat bookings is a common real-world problem.
This project simulates a basic bus management system using a console-based interface.

The program allows users to:
Add new buses
View all buses
Book and cancel seats
View seat availability
Search buses
Reset data
Display project credits

The project is intentionally kept simple and readable, making it ideal for learning and viva examinations.

⚙️ Features

Add bus details (ID, name, source, destination, seats)
Display all available buses
Book seats safely with validation
Cancel seat bookings
View seat map (0 = free, 1 = booked)
Search bus by ID
Search bus by name (substring)
Reset all stored data
Duo project credits displayed in menu

🧠 Concepts Used

struct for bus data representation
Arrays for storing multiple buses and seat status
Loops (for, do-while) for menu and data traversal
Conditional statements (if-else) for validation
Console input/output using scanf and printf

🛠️ Tech Stack

Language: C

Header File Used: stdio.h only

Compiler: GCC / MinGW

IDE: VS Code / CodeBlocks / Any C compiler

❗ No advanced libraries, no file handling, no void functions — beginner friendly.
▶️ How to Run the Program

1️⃣ Clone the Repository
git clone https://github.com/SPARSHsrihero1/bus-management-system-c.git
cd bus-management-system-c

2️⃣ Compile the Code
gcc bus.c -o bus

3️⃣ Run the Program
./bus

(On Windows, run bus.exe instead)

📸 Sample Menu (Console Output)
============================================
      BUS MANAGEMENT SYSTEM (DUO PROJECT)
============================================
1. Add Bus
2. Display All Buses
3. Book Seat
4. Cancel Booking
5. View Bus Details
6. Search Bus by ID
7. Search Bus by Name
8. Reset All Data
9. Project Credits
0. Exit

🚧 Limitations

Data is stored only during program execution
No permanent storage (no files used)
Limited number of buses and seats
Case-sensitive name search

🔮 Future Improvements

Add file handling to save data permanently
Include passenger name and contact details
Route-based bus search
Case-insensitive searching
Graphical user interface (GUI)
Dynamic memory allocation

🎯 Learning Outcome

This project helped us:
Understand real-world application of C programming
Improve logic building using arrays and structures
Learn menu-driven program design
Prepare for practical exams and viva


🙏 Acknowledgement

We sincerely thank Mr. Virender Kadyan for his guidance and support throughout this project.


📜 License

This project is created for educational purposes only.
Feel free to use, modify, and learn from it.
