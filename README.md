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

