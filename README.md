# Data-Structures
Data Structures and Algorithms Projects in C++
#  Overview
- This repository contains a collection of C++ projects implementing various data structures and algorithms. Developed as part of coursework at Cairo University in May 2025. Each project addresses a unique problem, showcasing skills in OOP, templates, file handling, and algorithmic design. The projects include:
  - A1: 

    - P1 - Iftar Invitation Manager for managing guest lists.
    - P2 - Polynomial Operations with addition and subtraction.
    - P3 - Sorted Linked List with insertion and indexing.
    - P4 - Sorting System with multiple algorithms and performance measurement.
    - P5 - Statistical Calculations for arrays (median, mean, etc.).
  - A2:
    - problem 1 - Browser History simulation using stacks.
    - problem 2 - AVL Tree-based Contact Book with file persistence.
    - Problem 3 - Binary Array Flipper using a greedy approach.
    - Problem 4 - Emergency Room Priority Queue using a max heap.

#  Features

- Diverse Data Structures - Includes linked lists, stacks, AVL trees, heaps, and dynamic arrays.
- Algorithmic Solutions - Sorting algorithms (e.g., merge sort, quicksort), statistical calculations, and greedy approaches.
- File I/O - Many projects read from and write to files (e.g., URL.txt, contacts.txt).
- Error Handling - Robust validation for user inputs and boundary conditions.
- Performance Measurement - Sorting system (P4) measures execution time for algorithms.

#  Usage
Each project can be compiled and run independently. Follow these steps to explore them:

  1 - Clone the Repository:

    Clone this repository to your local machine using:
    git clone https://github.com/mariam0905/Data-Structures.git
    
    
    Navigate to the project directory:
    cd repo-name




  2 - Compile a Project:

    Use a C++ compiler (e.g., g++) to compile the desired project. For example, to compile P1.cpp:
    g++ P1.cpp -o P1


    Repeat for other files (e.g., P2.cpp, stack.cpp, etc.).



  3 - Run a Project:

    Execute the compiled program. For example:
    ./P1
    
    
    Each project has its own interactive menu or input mechanism. Below are specific instructions for key projects.



  4 - Project-Specific Instructions:

  P1 (Iftar Manager):
      - Select options (1-7) to manage guests (e.g., add, remove, send reminders).
      
      Example:
      --- Iftar Invitation Manager ---
      1 - Add Guest
      2 - Remove Guest
      3 - Display Guest List
      Enter your choice: 1
      Enter guest name: Sara
      Enter contact number: 123456789
      Enter Iftar date (YYYY-MM-DD): 2025-04-05




  P4 (Sorting System):
    - Choose a data type (1-5), enter elements, and select a sorting algorithm (1-9).
    
    Example:
    Enter the number of elements: 5
    please enter the data type of the array:
    1 - Integer
    Enter your choice: 1
    Sorting System Menu:
    1 - Insertion Sort
    Enter your choice: 1
    Enter 5 elements: 64 34 25 12 22
    Sorted Data: 12 22 25 34 64
    Execution time: 0.000123 seconds




  problem 1 (Browser History):
    - Reads from URL.txt to simulate browser navigation (visit, go back/forward).
    
    Example output (from URL.txt):
    choice: Visit google.com
    Current URL: google.com
    BackStack: google.com -> homePage.com
    ForwardStack: (empty stack)
    choice: Go Back
    go back to: homePage.com




  problem 2 (Contact Book):
    - Loads contacts from contacts.txt, then use the menu to add, search, or delete contacts.
    
    Example:
    Address Book Application
    1 - Add New Contact
    Enter operation: 1
    Enter unique ID: 40
    Enter name: Sam
    Enter phone: 01234567891
    Enter email: sam@example.com
    Contact added successfully.




  Problem 4 (Emergency Room):
    - Reads patients from patients2.txt and processes them based on severity and arrival time.
    
    Example output:
    Patient Name: Ursula, Severity: 95, Arrival Time: 26
    Next patient: Ursula, Severity: 95, Arrival Time: 26







#  Input Files

- URL.txt - Navigation commands for stack.cpp.
- contacts.txt - Initial contacts for pb2.cpp.
- BinaryInput.txt - Test cases for Pb3.cpp.
- patients2.txt - Patient data for Problem4.cpp.

#  Limitations

- Projects are console-based with no graphical interfaces.
- Some projects (e.g., Pb3, Problem4) rely on predefined input files.
- Sorting in P4 for non-numeric types (e.g., strings) has limited support.
- Error handling varies across projects; some require manual input correction.

#  License
This project is licensed under the MIT License. See the LICENSE file for details.

#  Authors

- Mariam Hesham - [mariam0905]
- Computer Science Student at Cairo University

#  Acknowledgments

- Developed as part of coursework at Cairo University, May 2025.
- Thanks to instructors and peers for guidance.

