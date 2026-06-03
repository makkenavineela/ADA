# Analysis and Design of Algorithms Lab (23CS4PCADA)

### **Details**
* **Student Name:** Makkena Vineela
* **USN:** 1BF24CS162
* **Institution:** B.M.S. College of Engineering (BMSCE), Bengaluru
* **Department:** Computer Science and Engineering
* **Academic Year:** 2025 - 2026

---

## **Lab Program Directory Index**

| Sl. No. | Experiment Title | Paradigm / Technique | Lab C Program | LeetCode C Program |
| :--- | :--- | :--- | :--- | :--- |
| **1** | Topological Ordering of Digraph | Decrease & Conquer | [topological_sort.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/01_Topological_Sort/topological_sort.c) | [Course Schedule II (LC 210)](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/01_Topological_Sort/leetcode_210_course_schedule_ii.c) |
| **2** | Johnson-Trotter Permutations | Decrease & Conquer | [johnson_trotter.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/02_Johnson_Trotter/johnson_trotter.c) | *N/A* |
| **3** | Merge Sort with Timing Analysis | Divide & Conquer | [merge_sort.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/03_Merge_Sort/merge_sort.c) | [Sort an Array (LC 912)](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/03_Merge_Sort/leetcode_912_sort_an_array_merge.c) |
| **4** | Quick Sort with Timing Analysis | Divide & Conquer | [quick_sort.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/04_Quick_Sort/quick_sort.c) | [Kth Largest Element (LC 215)](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/04_Quick_Sort/leetcode_215_kth_largest_element_quickselect.c) |
| **5** | Heap Sort with Timing Analysis | Transform & Conquer | [heap_sort.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/05_Heap_Sort/heap_sort.c) | *N/A* |
| **6** | 0/1 Knapsack Problem | Dynamic Programming | [knapsack_01_dp.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/06_01_Knapsack_DP/knapsack_01_dp.c) | [Partition Equal Subset Sum (LC 416)](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/06_01_Knapsack_DP/leetcode_416_partition_equal_subset_sum.c) |
| **7** | All-Pairs Shortest Path (Floyd's) | Dynamic Programming | [floyds_apsp.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/07_Floyds_APSP/floyds_apsp.c) | [Threshold Distance City (LC 1334)](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/07_Floyds_APSP/leetcode_1334_find_city_threshold_distance.c) |
| **8** | Minimum Spanning Tree (MST) | Greedy Paradigm | [prims.c (Prim's)](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/08_Minimum_Spanning_Tree/prims.c) <br> [kruskal.c (Kruskal's)](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/08_Minimum_Spanning_Tree/kruskal.c) | *N/A* |
| **9** | Fractional Knapsack Problem | Greedy Paradigm | [fractional_knapsack.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/09_Fractional_Knapsack_Greedy/fractional_knapsack.c) | [Maximum Units on a Truck (LC 1710)](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/09_Fractional_Knapsack_Greedy/leetcode_1710_maximum_units_on_a_truck.c) |
| **10** | Single Source Shortest Path (Dijkstra's) | Greedy Paradigm | [dijkstras.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/10_Dijkstras_Shortest_Path/dijkstras.c) | *N/A* |
| **11** | N-Queens Backtracking | Backtracking | [n_queens.c](file:///C:/Users/dell/Desktop/ADA-main/ADA1bf24cs162/11_N_Queens_Backtracking/n_queens.c) | *N/A* |

---

## **How to Compile and Run**

Ensure you have a C compiler like `gcc` installed.

### **1. Basic Compilation**
To compile any C file, run the following command in your terminal:
```bash
gcc -o program_name path/to/file.c
```
*For example, to compile topological sort:*
```bash
gcc -o topological_sort ADA1bf24cs162/01_Topological_Sort/topological_sort.c
```

### **2. Running the Executable**
After successful compilation, run the compiled binary:
* **Windows (PowerShell/CMD):**
  ```powershell
  .\topological_sort.exe
  ```
* **Linux / macOS:**
  ```bash
  ./topological_sort
  ```