# Assignment 03 - Minimum Spanning Tree using CSR

## Course

**CS509 - Programming Lab**

## Assignment Type

**Individual Assignment**

---

## Student Details

- Name - Rakshit Gautam
- Entry Number - 2026CSM1032

---

# Objective

In this assignment, Minimum Spanning Tree (MST) algorithms are implemented using the Compressed Sparse Row (CSR) representation developed in Assignment 01.

The following algorithms are implemented:

- Kruskal's Minimum Spanning Tree Algorithm
- Prim's Minimum Spanning Tree Algorithm

The CSR conversion function from Assignment 01 is reused as required in the assignment specification.

The objective is to compute the Minimum Spanning Tree of an undirected weighted graph and compare the performance of both algorithms on graphs of different sizes.

---

# Algorithm Description

## 1. Kruskal's Algorithm

Kruskal's algorithm constructs the MST by repeatedly selecting the minimum-weight edge that does not create a cycle.

### Features

- Uses CSR graph representation
- Uses Disjoint Set Union (DSU)
- Processes edges in increasing order of weight
- Produces a Minimum Spanning Tree with minimum total weight

### Steps

1. Extract all edges from CSR representation.
2. Sort edges by weight.
3. Initialize DSU structure.
4. Add edges one by one if they do not form a cycle.
5. Stop when V−1 edges are selected.

---

## 2. Prim's Algorithm

Prim's algorithm grows the MST starting from vertex 0 as specified in the assignment.

### Features

- Uses CSR graph representation
- Uses Min Priority Queue
- Greedily expands the MST
- Produces a Minimum Spanning Tree with minimum total weight

### Steps

1. Start from vertex 0.
2. Insert adjacent edges into a priority queue.
3. Repeatedly select the minimum-weight edge.
4. Add the new vertex to MST.
5. Continue until all vertices are included.

---

# Input Format

```text
V E

u0 degree neighbor1 weight1 neighbor2 weight2 ...
u1 degree neighbor1 weight1 neighbor2 weight2 ...
...
u(V-1) degree neighbor1 weight1 neighbor2 weight2 ...
```

## Example

```text
5 7

0 2 1 2 2 6
1 3 0 2 2 3 3 8
2 3 0 6 1 3 4 7
3 2 1 8 4 5
4 2 2 7 3 5
```

---

# Output Format

## Kruskal

```text
Algorithm: Kruskal's MST

MST edges:
0 1 2
1 2 3
3 4 5
2 4 7

Total MST weight: 17

Execution Time: X ms
```

---

## Prim

```text
Algorithm: Prim's MST

MST edges:
0 1 2
1 2 3
3 4 5
2 4 7

Total MST weight: 17

Execution Time: X ms
```

---

# Folder Structure

```text
CS509_2026CSM1032/
|
├── common_wrapper/
│   └── wrapper.cpp
|
├── assignment_1/
│
├── assignment_2/
│
└── assignment_3/
    |
    ├── driver/
    │   ├── main_driver.cpp
    │   ├── kruskal_driver.cpp
    │   └── prim_driver.cpp
    |
    ├── src/
    │   ├── kruskal.cpp
    │   ├── kruskal.h
    │   ├── prim.cpp
    │   └── prim.h
    |
    ├── tests/
    │   
    |
    └── outputs/
```

---

# File Description

| File | Description |
|--------|--------|
| kruskal.cpp | Kruskal MST implementation |
| kruskal.h | Kruskal declarations |
| prim.cpp | Prim MST implementation |
| prim.h | Prim declarations |
| kruskal_driver.cpp | Reads graph input and executes Kruskal MST |
| prim_driver.cpp | Reads graph input and executes Prim MST |
| main_driver.cpp | Menu-driven execution of Assignment 03 |
| README.md | Assignment documentation |

---

# Compilation

## Kruskal

```bash
g++ driver/kruskal_driver.cpp src/kruskal.cpp ../assignment_1/src/csr.cpp -o kruskal.exe
```

## Prim

```bash
g++ driver/prim_driver.cpp src/prim.cpp ../assignment_1/src/csr.cpp -o prim.exe
```

---

# Execution

Run Assignment 03:

```bash
assignment_3.exe
```

The program displays:

```text
1. Kruskal MST
2. Prim MST
0. Exit
```

Select the desired algorithm and then choose the required test file.

Outputs are automatically generated inside the outputs directory.

---

# Time Complexity

## Kruskal

```text
O(E log E)
```

Sorting of edges dominates the running time.

---

## Prim

```text
O(E log V)
```

Using a priority queue implementation.

---

# Space Complexity

## Kruskal

```text
O(V + E)
```

---

## Prim

```text
O(V + E)
```

---

# Result Table

| Test File | Vertices | Edges | Kruskal MST Weight | Prim MST Weight | Kruskal Time (ms) | Prim Time (ms) | Weight Match | Status |
|------------|---------:|------:|-------------------:|----------------:|------------------:|---------------:|--------------|--------|
| mst_10.txt | 10 | 20 | 290 | 290 | 0 ms | 0 ms | yes | pass |
| mst_100_a.txt | 100 | 200 | 2421 | 2421 | 1.149 ms | 1.035 ms | yes | pass |
| mst_100_b.txt | 100 | 400 | 1570 | 1570 | 0 ms | 0.998 ms | yes | pass |
| mst_10000_a.txt | 10000 | 20000 | 291461 | 291461 | 7.999 ms | 19.631 ms | yes | pass |
| mst_10000_b.txt | 10000 | 40000 | 153388 | 153388 | 18.695 ms | 40.572 ms | yes | pass |
| mst_50000_a.txt | 50000 | 100000 | 1458700 | 1458700 | 48.551 ms | 135.607 ms | yes | pass |
| mst_50000_b.txt | 50000 | 200000 | 764914 | 764914 | 103.804 ms | 237.53 ms | yes | pass |
| mst_100000_a.txt | 100000 | 200000 | 2898613 | 2898613 | 111.724 ms | 443.154 ms | yes | pass |
| mst_100000_b.txt | 100000 | 400000 | 1538946 | 1538946 | 209.712 ms | 743.845 ms | yes | pass|

---

# Findings / Observations

1. Both Kruskal's and Prim's algorithms produced MSTs with the same total weight for all test cases, validating correctness.

2. Kruskal's algorithm spends a significant amount of time sorting edges. For larger graphs, sorting becomes the dominant cost.

3. Prim's algorithm avoids global edge sorting and generally performs better on sparse graphs when implemented using a priority queue.

4. CSR representation significantly reduces memory consumption compared to adjacency matrix representation.

5. The CSR conversion function implemented in Assignment 01 was reused successfully without modification.

6. Execution time increases with graph size, but both implementations remain practical for large sparse graphs.


---

# Compiler

- Language : C++
- Compiler : g++

---

# References

1. Assignment 03 Specification
2. GeeksforGeeks
3. CLRS Algorithms
4. Striver DSA