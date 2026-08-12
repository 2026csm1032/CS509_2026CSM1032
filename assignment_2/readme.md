# Assignment 02 - Graph Algorithms using CSR

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

In this assignment, graph algorithms are implemented using the Compressed Sparse Row (CSR) representation developed in Assignment 01.

The following algorithms are implemented:

- Bellman-Ford Single Source Shortest Path (SSSP)
- Floyd-Warshall All Pairs Shortest Path (APSP)

The CSR conversion function from Assignment 01 is reused as required in the assignment specification.

---

# Algorithm Description

## 1. Bellman-Ford Algorithm

Bellman-Ford computes the shortest distance from a source vertex to every other vertex in a weighted directed graph.

Features:

- Supports positive edge weights
- Supports negative edge weights
- Detects negative weight cycles
- Uses CSR representation for graph storage

If a negative cycle is reachable from the source vertex, the algorithm reports it.

---

## 2. Floyd-Warshall Algorithm

Floyd-Warshall computes shortest paths between every pair of vertices.

Features:

- Computes all-pairs shortest paths
- Supports negative edge weights
- Detects negative cycles
- Produces a complete shortest-distance matrix

If any diagonal element becomes negative after computation, a negative cycle exists in the graph.

---

# Input Format

## Bellman-Ford

```text
V E
u0 degree neighbor1 weight1 neighbor2 weight2 ...
u1 degree neighbor1 weight1 neighbor2 weight2 ...
...
u(V-1) degree neighbor1 weight1 neighbor2 weight2 ...
SOURCE s
```

### Example

```text
5 10
0 2 1 6 3 7
1 3 2 5 3 8 4 -4
2 1 1 -2
3 2 2 -3 4 9
4 2 0 2 2 7
SOURCE 0
```

---

## Floyd-Warshall

```text
V
row 0 values
row 1 values
...
row (V-1) values
```

### Example

```text
5
0 3 8 INF -4
INF 0 INF 1 7
INF 4 0 INF INF
2 INF -5 0 INF
INF INF INF 6 0
```

---

# Output Format

## Bellman-Ford

```text
Algorithm: Bellman-Ford
Source: 0

Vertex Distance
0 0
1 2
2 4
3 7
4 -2

Negative Cycle: none

Execution Time: <value> ms
```

If a negative cycle exists:

```text
Negative Cycle: true
```

---

## Floyd-Warshall

```text
Algorithm: Floyd-Warshall

Distance Matrix:
0 1 -3 2 -4
3 0 -4 1 -1
7 4 0 5 3
2 -1 -5 0 -2
8 5 1 6 0

Negative Cycle: none

Execution Time: <value> ms
```

If a negative cycle exists:

```text
Negative Cycle: true
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
└── assignment_2/
    |
    ├── driver/
    │   ├── main_driver.cpp
    │   ├── bellman_ford_driver.cpp
    │   └── floyd_warshall_driver.cpp
    |
    ├── src/
    │   ├── bellman_ford.cpp
    │   ├── bellman_ford.h
    │   ├── floyd_warshall.cpp
    │   └── floyd_warshall.h
    |
    ├── tests/
    │   ├── bellman_ford/
    │   └── floyd_warshall/
    |
    └── outputs/
```

---

# File Description

| File | Description |
|--------|--------|
| bellman_ford.cpp | Bellman-Ford algorithm implementation |
| bellman_ford.h | Bellman-Ford declarations |
| floyd_warshall.cpp | Floyd-Warshall algorithm implementation |
| floyd_warshall.h | Floyd-Warshall declarations |
| bellman_ford_driver.cpp | Reads graph input and executes Bellman-Ford |
| floyd_warshall_driver.cpp | Reads matrix input and executes Floyd-Warshall |
| main_driver.cpp | Menu-driven execution of Assignment 02 |
| README.md | Assignment documentation |

---

# Compilation

## Bellman-Ford

```bash
g++ driver/bellman_ford_driver.cpp src/bellman_ford.cpp ../assignment_1/src/csr.cpp -o bellman_ford.exe
```

## Floyd-Warshall

```bash
g++ driver/floyd_warshall_driver.cpp src/floyd_warshall.cpp -o floyd_warshall.exe
```

---

# Execution

Run Assignment 02:

```bash
assignment_2.exe
```

The program displays a menu:

```text
1. Bellman-Ford
2. Floyd-Warshall
0. Exit
```

Select the desired algorithm and then choose the required test file.

Output files are generated automatically inside the outputs directory.

---

# Time Complexity

## Bellman-Ford

```text
O(V × E)
```

---

## Floyd-Warshall

```text
O(V³)
```

---

# Space Complexity

## Bellman-Ford

```text
O(V + E)
```

---

## Floyd-Warshall

```text
O(V²)
```

---

# Bellman-Ford / Floyd-Warshall Results

| Algorithm | Test File | Vertices | Edges | Source | Negative Cycle | Expected Output | Time (ms) | Status |
|------------|------------|---------:|------:|--------|----------------|----------------|----------:|--------|
| Bellman-Ford | test_01.txt | 10 | 24 | 9 | No | Distances | 0.00 ms | Pass |
| Bellman-Ford | test_02.txt | 20 | 54 | 2 | No | Distances | 0.00 ms | Pass |
| Bellman-Ford | test_03.txt | 50 | 144 | 32 | No | Distances | 0.00 ms | Pass |
| Bellman-Ford | test_04.txt | 100 | 294 | 24 | No | Distances | 1.316 ms | Pass |
| Bellman-Ford | test_05.txt | 500 | 1494 | 313 | No | Distances | 1.114 ms | Pass |
| Bellman-Ford | test_06.txt | 1000 | 2994 | 334 | No | Distances | 0.00 ms | Pass |
| Bellman-Ford | test_07.txt | 5000 | 14994 | 1978 | No | Distances | 0.00 ms | Pass |
| Bellman-Ford | test_08.txt | 10000 | 29994 | 927 | No | Distances | 1.004 ms | Pass |
| Bellman-Ford | test_09.txt | 50000 | 149994 | 24737 | No | Distances | 6.994 ms | Pass |
| Bellman-Ford | test_10.txt | 100000 | 299994 | 12647 | No | Distances | 14.561 ms | Pass |
| Floyd-Warshall | test_01.txt | 5 | N/A | N/A | No | Distance Matrix | 0.00 ms | Pass |
| Floyd-Warshall | test_02.txt | 10 | N/A | N/A | No | Distance Matrix | 0.00 ms | Pass |
| Floyd-Warshall | test_03.txt | 20 | N/A | N/A | No | Distance Matrix | 0.00 ms | Pass |
| Floyd-Warshall | test_04.txt | 30 | N/A | N/A | No | Distance Matrix | 0.983 ms | Pass |
| Floyd-Warshall | test_05.txt | 50 | N/A | N/A | No | Distance Matrix | 3.102 ms | Pass |
| Floyd-Warshall | test_06.txt | 75 | N/A | N/A | No | Distance Matrix | 12.012 ms | Pass |
| Floyd-Warshall | test_07.txt | 100 | N/A | N/A | No | Distance Matrix | 27.797 ms | Pass |
| Floyd-Warshall | test_08.txt | 150 | N/A | N/A | No | Distance Matrix | 95.217 ms | Pass |


---

# Timing Methodology

- Timer starts immediately before the algorithm call.
- Timer stops immediately after the algorithm finishes.
- CSR conversion time is not included.
- Input parsing time is not included.
- Output generation and file writing time are not included.
- Execution time is reported in milliseconds.

---

# Compiler

- Language : C++
- Compiler : g++

---

# References

1. Assignment 02 Specification
2. GeeksforGeeks
3. CLRS Algorithms
4. Striver DSA