# Data Structures Assignment

This assignment was developed as part of a university course on data structures. It was implemented collaboratively with my teammate Mohanned Abdelazem and Abdelrahman Ashraf. The assignment focuses on implementing AVL trees, Binary Search Trees (BST), and heaps. Additionally, it includes an application that allows users to interact with these data structures.

## Project Structure

The project consists of the following components:

1. **Student**

   The `Student` class represents a student entity with attributes such as `id`, `name`, `gpa`, and `department`. It provides methods to set and get these attributes, as well as a `print()` method to display the student's information.

2. **Trees**

   The `Trees` component includes the implementation of AVL trees and BST.

   - `BST` class: Implements a binary search tree. It provides methods for inserting, removing, searching, and printing the elements of the tree.
   - `AVL` class: Extends the BST class and implements an AVL tree, which is a self-balancing binary search tree. It provides methods for inserting and removing elements while maintaining the AVL tree's balance.

3. **Heap**

   The `Heap` component includes the implementation of a heap data structure and sorting algorithms.

   - `HeapSort` class: Implements a heap data structure and sorting algorithms using the heap. It provides methods for inserting elements into the heap and printing the elements in ascending or descending order, depending on the heap type (min or max).

4. **Controller**

   The `Controller` class serves as the main application for interacting with the data structures. It provides a menu-based interface for the user to choose between the BST, AVL, min heap, or max heap options. Within each option, the user can perform various operations such as adding students, removing students, searching for students, and printing the elements.

## Usage

To use the provided data structures and run the application, follow these steps:

1. Include the necessary header files in your code:

   ```cpp
   #include "Student.h"
   #include "BST.h"
   #include "AVL.h"
   #include "HeapSort.h"
   #include <fstream>
   ```
2. Implement the `Controller` class and its methods as shown in the provided code.

3. Create an instance of the `Controller` class and start the application:

    ```cpp
    int main() {
        Controller app;
        app.start();
        return 0;
    }
    ```
4. Compile and run the program.

5. Follow the instructions in the console to interact with the data structures and perform operations such as adding, removing, searching, and printing students.

Note: The program also includes a `readFile()` method in the `Controller` class, which reads student information from a file named "file.txt". Make sure to provide the file with the correct format and path if you want to populate the data structures with student data from the file.

Feel free to explore and modify the provided code to suit your specific requirements. Enjoy working with data structures!
