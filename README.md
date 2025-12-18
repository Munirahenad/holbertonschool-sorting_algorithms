# holbertonschool-sorting_algorithms
## Sorting Algorithms

## 📌 Description
This project contains implementations of multiple sorting algorithms in **C**, developed as part of the **Holberton School curriculum**.

The project focuses on understanding how different sorting algorithms work, comparing their efficiency, and analyzing their **time complexity (Big O notation)**.  
All algorithms sort integers in **ascending order** and follow Holberton’s output and formatting requirements.

---

## 🧠 Learning Objectives
By completing this project, you should be able to:

- Explain and implement various sorting algorithms
- Understand and apply **Big O notation**
- Choose the appropriate sorting algorithm for a given input
- Distinguish between **stable** and **unstable** sorting algorithms
- Work with arrays and doubly linked lists
- Perform **in-place sorting**

---

## 📁 Project Structure

| File / Folder | Description |
|--------------|-------------|
| `sort.h` | Header file containing function prototypes and data structures |
| `*.c` | Sorting algorithm implementations |
| `*-O` | Time complexity files |
| `README.md` | Project documentation |

---

## 🧩 Data Structures

### Doubly Linked List
```c
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
The listint_t structure is used by sorting algorithms that operate on doubly linked lists, such as Insertion Sort and Cocktail Shaker Sort.
Each node stores an integer value and pointers to both the previous and next nodes, allowing efficient bidirectional traversal.

🚀 Implemented Algorithms
🟢 Bubble Sort
Files: 0-bubble_sort.c, 0-O

Data Structure: Array

Method: Comparison

Prints the array after every swap

Time Complexity

Best: O(n)

Average: O(n²)

Worst: O(n²)

🟢 Insertion Sort (Doubly Linked List)
Files: 1-insertion_sort_list.c, 1-O

Swaps nodes directly

Prints the list after every swap

Time Complexity

Best: O(n)

Average: O(n²)

Worst: O(n²)

🟢 Selection Sort
Files: 2-selection_sort.c, 2-O

Selects the minimum element and places it in order

Prints the array after every swap

Time Complexity

Best: O(n²)

Average: O(n²)

Worst: O(n²)

🟢 Quick Sort (Lomuto Partition)
Files: 3-quick_sort.c, 3-O

Divide-and-conquer algorithm

Prints the array after every swap

Time Complexity

Best: O(n log n)

Average: O(n log n)

Worst: O(n²)
