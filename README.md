cat << 'EOF' > README.md
# holbertonschool-sorting_algorithms
## Sorting Algorithms

## 📌 Description
This project contains implementations of several sorting algorithms in C.  
Each algorithm sorts integers in ascending order and follows specific output and complexity requirements.

---

## 🧠 Learning Objectives
By completing this project, you should be able to:

- Explain multiple sorting algorithms
- Understand and use Big O notation
- Choose the appropriate sorting algorithm for a given input
- Distinguish between stable and unstable sorting algorithms

---

## 📂 Project Structure

| File | Description |
|------|-------------|
| sort.h | Header file containing all function prototypes |
| *.c | Sorting algorithm implementations |
| *-O | Time complexity files |
| README.md | Project documentation |

---

## 🔢 Implemented Algorithms

| Algorithm | Method | Data Structure |
|---------|--------|---------------|
| Bubble Sort | Comparison | Array |
| Insertion Sort | Comparison | Array |
| Selection Sort | Comparison | Array |
| Merge Sort | Divide & Conquer | Array |
| Heap Sort | Binary Heap | Array |
| Quick Sort | Hoare Partition | Array |
| Radix Sort | Non-comparison | Array |
| Bitonic Sort | Parallel Algorithm | Array |

---

## ⏱️ Time Complexity (Big O)

| Algorithm | Best Case | Average Case | Worst Case |
|---------|-----------|--------------|------------|
| Bubble Sort | O(n) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |
| Radix Sort | O(n + k) | O(n + k) | O(n + k) |
| Bitonic Sort | O(n log² n) | O(n log² n) | O(n log² n) |

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

## 👤 Authors
- Munirah Enad
- Hamsa Alammar


















































































































